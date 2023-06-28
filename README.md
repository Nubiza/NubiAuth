# NubiAuth
Nubi Auth is c++ simple authentication made by Nubiza
<br />
HTTP / HTTPS Support (Support SSL)

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

## Full auth (Username & Password)
Username & Full Auth is different
|**Parameter**|**Value**|
|-------------|---------|
|POST|`https://auth.nubizaserver.my.id/auth.php`|
|ApiKey|`Your Api key`|
|username|`username`|
|password|`password`|

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
Username & Full Auth is different
|**Parameter**|**Value**|
|-------------|---------|
|POST|`https://auth.nubizaserver.my.id/add-new-user.php`|
|ApiKey|`Your Api key`|
|SecretKey|`Your Secret key`|
|username|`username`|
|password|`password`|
