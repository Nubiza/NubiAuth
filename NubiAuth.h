#pragma once
#include <curl/curl.h> // use libcurl
// See Example.cpp for example


class NubiAuth {
private:
  const char* ApiKey = ""; // your Api Key (to get your Api Key login to auth.nubizaserver.my.id
  const char* Auth_Link = "https://auth.nubizaserver.my.id/auth.php";

  bool ProcessRequest(std::string request_response) {
    if (resp.find("User|Access") != -1) {
      if (resp.find("device_id saved") != -1)
      printf("Device id saved!\n");
      return true;
    }
    else if (resp.find("User|Wrong") != -1) {
      printf("Wrong username or password.\n");
      return false;
    }
    else if (resp.find("User|Denied") != -1) {
      printf("Device id not Authorized.\n");
      return false;
    }
    else if (resp.find("ApiKey|Limit") != -1) {
      printf("ApiKey reached limit.\n");
      return false;
    }
    else if (resp.find("ApiKey not found") != -1) {
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

  std::string RequestPost(char* url, char* request_headers, char* post_fields, bool verify_host = false, bool verify_peer = false) {
    CURL *curl;
    std::string readBuffer;
    struct curl_slist *headers = NULL;
    curl = curl_easy_init();
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
        curl_easy_perform(curl);
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
    const std::string body = "ApiKey="+ApiKey+"&username="+username+"&device_id=" + device_id;
    std::string resp = RequestPost(Auth_Link, "Content-Type: application/x-www-form-urlencoded", body.c_str(), true, true);
    return ProcessRequest(resp);
  }

  // login using user name and password
  // (different database, Username & Password in dashboard)
  bool login(std::string username, std::string user_password) {
    if (device_id.empty() || device_id == "") {
      printf("device_id is not set, exiting...");
      exit(1);
    }
    const std::string body = "ApiKey=" + ApiKey + "&username=" + username + "&password=" + user_password + "&device_id=" + device_id;
    std::string resp = RequestPost(Auth_Link, "Content-Type: application/x-www-form-urlencoded", body.c_str(), true, true);
    return ProcessRequest(resp);
  }
};
