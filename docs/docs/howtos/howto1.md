# How to blow up a jetpack

Generally speaking there are three steps one can take in order to get rid of a jetpack that has become a burden.

## Step 1: prepare the explosion

Check amount of fuel remaining inside the jetpack since it directly affects the size of explosion. Here's how to do it:

``tabs
``page
title: Blueprint
Check the `Remaining Fuel` variable of class [Jetpack](api/blueprint/Jetpack/Jetpack "Jetpack")
``
``page
title: C++
Check the `RemainingFuel` field of class [AJetpack](api/cpp/Jetpack/AJetpack "AJetpack")
``
``

Make sure the jetpack isn't being fueled:

``tabs
``page
title: Blueprint
Call [Get State](api/blueprint/Jetpack/Jetpack/Get_State "Get State") function of class [Jetpack](api/blueprint/Jetpack/Jetpack "Jetpack") and make sure the returned value isn't equal to [FUELING](api/blueprint/Jetpack/EJetpack_State "FUELING").
``
``page
title: C++
Call [GetState()](api/cpp/Jetpack/AJetpack/GetState "GetState()") method of class [AJetpack](api/cpp/Jetpack/AJetpack "AJetpack") and make sure the returned value isn't equal to [EJetpackState::FUELING](api/cpp/Jetpack/Jetpack.h/EJetpackState "FUELING").
``
``

## Step 2: choose the explosion parameters

The only option available when blowing up a jetpack is choosing the size of the resultant explosion which then will be multiplied by internal coefficients of jetpack. Those coefficients are affected e.g. by amount of fuel remaining inside the jetpack.

The explosion size cannot be negative but can be as big as needed if kept positive.

## Step 3: blow it up

Call the corresponding function in your language of choice:

``tabs
``page
title: Blueprint
Call [Blow It Up](api/blueprint/Jetpack/Jetpack/Blow_It_Up "Blow It Up") function of class [Jetpack](api/blueprint/Jetpack/Jetpack "Jetpack").
``
``page
title: C++
Call [BlowItUp()](api/cpp/Jetpack/AJetpack/BlowItUp "BlowItUp()") method of class [AJetpack](api/cpp/Jetpack/AJetpack "AJetpack").
``
``

``attention
title: Safety first
When blowing jetpacks up, always wear protective glasses!
``
