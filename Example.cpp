#include <iostream>
#include "NubiAuth.h"
#include "android_device_id.h"
#include "obfuscate.h"

int main()
{
    std::cout << "NubiAuth Example.\n\n";

    string user_name = "";
    std::cout << AY_OBFUSCATE("Username : "); std::cin >> user_name;

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
