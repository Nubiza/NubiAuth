#pragma once
#include <iostream>
#include <sys/system_properties.h>
using namespace std;

std::string get_device_id() {
    char device[PROP_VALUE_MAX+1];
    char name[PROP_VALUE_MAX+1];
    char brand[PROP_VALUE_MAX+1];
    char board[PROP_VALUE_MAX+1];
    char manufact[PROP_VALUE_MAX+1];
    char cpuabi[PROP_VALUE_MAX+1];
    //char cpuabi2[PROP_VALUE_MAX+1]; not used
    __system_property_get("ro.product.device", device);
    __system_property_get("ro.product.name", name);
    __system_property_get("ro.product.brand", brand);
    __system_property_get("ro.board.platform", board);
    __system_property_get("ro.product.manufacturer", manufact);
    __system_property_get("ro.product.cpu.abilist", cpuabi);
    std::string manufacturer = manufact;
    if (manufacturer.find(" ")) {
        manufacturer.substr(0, manufacturer.find(" "));
    }
    std::string deviceid = string(device)+string(name)+string(brand)+string(board)+string(manufacturer)+string(cpuabi)+string(cpuabi);
    return deviceid;
}
