#pragma once
#include <iostream>
#include <string>

std::string encrypt(const std::string& message, const std::string& key) {
    std::string encryptedMessage = message;
    for (size_t i = 0; i < encryptedMessage.length(); ++i) {
        encryptedMessage[i] ^= key[i % key.length()];
    }
    return encryptedMessage;
}

std::string decrypt(const std::string& encryptedMessage, const std::string& key) {
    return encrypt(encryptedMessage, key); // XOR encryption is reversible
}
