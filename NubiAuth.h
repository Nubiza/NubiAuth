#pragma once
#include "HTTPRequest.hpp"

// See Example.cpp for example

class NubiAuth {
  public:
  bool isAuth = false;

  std::string ApiKey = ""; // your Api Key (to get your Api Key login to auth.nubizaserver.my.id
  std::string device_id = ""; // device id (example in NubiAuth.cpp)

  // login using user name only
  // (Username Only in dashboard)
  bool login(std::string username) {
    if (device_id.empty() || device_id == "") {
      printf("device_id is not set, exiting...");
      exit(1);
    }
    http::Request request {
      "http://auth.nubizaserver.my.id/auth.php"
    };
    const std::string body = "ApiKey="+ApiKey+"&username="+username+"&device_id=" + device_id;
    const auto response = request.send(
      "POST",
      body,
      {
        {
          "Content-Type", "application/x-www-form-urlencoded"
        }
      }
    );
    std::string resp = std::string({
      response.body.begin(), response.body.end()
    });
    if (resp.find("User|Access") != -1) {
      if (resp.find("device_id saved") != -1)
      printf("Device id saved!\n");
      isAuth = true;
      return true;
    }
    else if (resp.find("User|Wrong") != -1) {
      printf("Wrong username.\n");
      isAuth = false;
      return false;
    }
    else if (resp.find("User|Denied") != -1) {
      printf("Device id not Authorized.\n");
      isAuth = false;
      return false;
    }
    else if (resp.find("ApiKey not found") != -1) {
      printf("%s\n", resp.c_str());
      isAuth = false;
      return false;
    }
    else {
      printf("Server is offline/error (?)\n");
      isAuth = false;
      return false;
    }
  }

  // login using user name and password
  // (different database, Username & Password in dashboard)
  bool login(std::string username, std::string user_password) {
    if (device_id.empty() || device_id == "") {
      printf("device_id is not set, exiting...");
      exit(1);
    }
    http::Request request {
      "http://auth.nubizaserver.my.id/auth.php"
    };
    const std::string body = "ApiKey=" + ApiKey + "&username=" + username + "&password=" + user_password + "&device_id=" + device_id;
    const auto response = request.send(
      "POST",
      body,
      {
        {
          "Content-Type", "application/x-www-form-urlencoded"
        }
      }
    );
    std::string resp = std::string({
      response.body.begin(), response.body.end()
    });
    if (resp.find("User|Access") != -1) {
      if (resp.find("device_id saved") != -1)
      printf("Device id saved!\n");
      isAuth = true;
      return true;
    }
    else if (resp.find("User|Wrong") != -1) {
      printf("Wrong username or password.\n");
      isAuth = false;
      return false;
    }
    else if (resp.find("User|Denied") != -1) {
      printf("Device id not Authorized.\n");
      isAuth = false;
      return false;
    }
    else if (resp.find("ApiKey not found") != -1) {
      printf("%s\n", resp.c_str());
      isAuth = false;
      return false;
    }
    else {
      printf("Server is offline/error (?)\n");
      isAuth = false;
      return false;
    }
  }
};
