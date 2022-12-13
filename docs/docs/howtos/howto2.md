# How to deploy a navigational beacon

``warning
Deployment of navigational beacons can only be accomplished using Blueprint. This functionality isn't available in C++
``

In order to deploy a navigation beacon one needs to create an instance of [BP Navigator Extension](api/blueprint/<Content>/BP_Navigator_Extension "BP Navigator Extension") and attach it to a jetpack using [Extend](api/blueprint/Jetpack/Jetpack/Extend "Extend") function.

After that the only thing that needs to be done in order for deployment of navigational beacons to happen is a call of [Deploy Beacon](api/blueprint/<Content>/BP_Navigator_Extension/Deploy_Beacon "Deploy Beacon").

![Deploy Beacon Signature](images/Deploy_Beacon.png)

The only available parameter `Target Location` is a 3D-location to aim to when deploying a beacon. Note, that the resultant location of the beacon deployed may differ from `Target Location` by ±10%. The actual location of the deployed beacon is returned by `Location` out-parameter. `Is Sucessful Deployment` indicates whether a beacon was actually deployed in which case its value will be equal to `True`. In case it's `False`, the value of `Location` isn't specified.
