# NubiAuth using libcurl to HTTPS Request Post
Make sure libcurl is instaled in your device
Nubi Auth is c++ simple authentication made by Nubiza
<br />
HTTPS Only

# Dashboard
Get your Api Key & Secret Key here
<br />
https://auth.nubizaserver.my.id/

# How to use NubiAuth (Check on NubiAuth.cpp)
## Username Only
|**Parameter**|**Value**|
|-------------|---------|
|POST|`https://auth.nubizaserver.my.id/auth.php`|
|ApiKey|`Your Api key`|
|username|`username`|
|device_id|`device_id (if in database empty it will save the device_id)`|


## Full auth (Username & Password)
Username & Full Auth is different
|**Parameter**|**Value**|
|-------------|---------|
|POST|`https://auth.nubizaserver.my.id/auth.php`|
|ApiKey|`Your Api key`|
|username|`username`|
|password|`password`|
|device_id|`device_id (if in database empty it will save the device_id)`|

<br />
<br />

# How to add new user
## Username Only
|**Parameter**|**Value**|
|-------------|---------|
|POST|`https://auth.nubizaserver.my.id/add-new-user.php`|
|ApiKey|`Your Api key`|
|SecretKey|`Your Secret key`|
|username|`username`|

## Full auth (Username & Password)
Username Only & Full Auth is different
|**Parameter**|**Value**|
|-------------|---------|
|POST|`https://auth.nubizaserver.my.id/add-new-user.php`|
|ApiKey|`Your Api key`|
|SecretKey|`Your Secret key`|
|username|`username`|
|password|`password`|
