#include <iostream>
#include "NubiAuth.h"
#include "android_device_id.h"

int main()
{
    printf("NubiAuth Example.\n\n");

    string user_name = "";
    printf("Username : "); std::cin >> user_name;

    // -------- NubiAuth Example --------
    NubiAuth auth;
    // api key from https://auth.nubizaserver.my.id/
    auth.ApiKey = "Your Api Key here";
    // set device id
    auth.device_id = get_device_id();
    if (auth.login(user_name)) {
        printf("\nLogged In!\n");

        while (1);
    }
    // -------- NubiAuth Example --------
}
