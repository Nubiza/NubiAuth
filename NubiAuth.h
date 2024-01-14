#pragma once
#include <curl/curl.h> // use libcurl
#include "obfuscate.h"
// See Example.cpp for example

#define strg std::string
#define OBF(string) AY_OBFUSCATE(string)

class NubiAuth {
private:
  const char* ApiKey = OBF("Your ApiKey"); // your Api Key (to get your Api Key login to auth.nubizaserver.my.id
  const char* Auth_Link = OBF("https://auth.nubiza.my.id/auth.php");

  bool ProcessRequest(std::string resp) {
    if (resp.find(OBF("User|Access")) != -1) {
      if (resp.find(OBF("device_id saved")) != -1)
      printf("Device id saved!\n");
      return true;
    }
    else if (resp.find(OBF("User|Wrong")) != -1) {
      printf("Wrong username or password.\n");
      return false;
    }
    else if (resp.find(OBF("User|Denied")) != -1) {
      printf("Device id not Authorized.\n");
      return false;
    }
    else if (resp.find(OBF("ApiKey|Limit")) != -1) {
      printf("ApiKey reached limit.\n");
      return false;
    }
    else if (resp.find(OBF("ApiKey not found")) != -1) {
      printf("%s\n", resp.c_str());
      return false;
    }
    else {
      printf("Server is offline/error (?)\n");
      return false;
    }
  }
public:
  // Public Variables
  std::string device_id = ""; // device id (example in NubiAuth.cpp)
  static size_t WCallback(void *contents, size_t size, size_t nmemb, void *userp) //Write Callback
  {
      ((std::string *)userp)->append((char *)contents, size * nmemb);
      return size * nmemb;
  }

  std::string RequestPost(const char* url, const char* request_headers, const char* post_fields, bool verify_host = false, bool verify_peer = false) {
    CURL *curl;
    std::string readBuffer;
    struct curl_slist *headers = NULL;
    curl = curl_easy_init();
    CURLcode res;
    if (curl)
    {
        headers = curl_slist_append(headers, request_headers);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 5000);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, verify_host);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, verify_peer);
        curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
          if (strg(url).find("://nubiza.my.id") != -1) {
            char* remote_address;
            res = curl_easy_getinfo(curl, CURLINFO_PRIMARY_IP, &remote_address);
            strg auth_address(OBF("103.134.152.6"));
            if (strg(remote_address) != auth_address) {
              readBuffer = "";
              printf("Invalid server: %s\n", remote_address);
            }
          }
        } else {
          printf("Failed to connect the server.\n");
        }
        curl_easy_cleanup(curl);
        return readBuffer;
    }
    return "Curl Failed";
  }


  // login using user name only
  // (Username Only in dashboard)
  bool login(std::string username) {
    if (device_id.empty() || device_id == "") {
      printf("device_id is not set, exiting...");
      exit(1);
    }
    const std::string body = (strg)"ApiKey=" + (strg)this->ApiKey + (strg)"&username=" + username + (strg)"&device_id=" + device_id;
    std::string resp = RequestPost(Auth_Link, "Content-Type: application/x-www-form-urlencoded", body.c_str(), true, true);
    return this->ProcessRequest(resp);
  }

  // login using user name and password
  // (different database, Username & Password in dashboard)
  bool login(std::string username, std::string user_password) {
    if (device_id.empty() || device_id == "") {
      printf("device_id is not set, exiting...");
      exit(1);
    }
    const std::string body = (strg)"ApiKey=" + (strg)this->ApiKey + (strg)"&username=" + username + (strg)"&password=" + user_password + (strg)"&device_id=" + device_id;
    std::string resp = RequestPost(Auth_Link, "Content-Type: application/x-www-form-urlencoded", body.c_str(), true, true);
    return this->ProcessRequest(resp);
  }
};
