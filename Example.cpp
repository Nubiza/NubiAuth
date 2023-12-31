#include <iostream>
#include "NubiAuth.h"
#include "android_device_id.h"
#include "obfuscate.h"

int main()
{
    std::cout << "NubiAuth Example.\n\n";

    std::string user_name = "";
    std::cout << AY_OBFUSCATE("Username : "); std::cin >> user_name;

    // -------- NubiAuth Example --------
    NubiAuth auth;
    // set api key from https://auth.nubizaserver.my.id/ in NubiAuth.h
    auth.device_id = get_device_id();
    if (auth.login(user_name)) {
        printf("\nLogged In!\n");

        while (1);
    }
    // -------- NubiAuth Example --------
}
