# Urban Airship PhoneGap/Cordova Plugin modified for AppGyver Steroids

This plugin supports PhoneGap/Cordova apps running on both iOS and Android. Full documentation is
available [here](http://docs.urbanairship.com/platform/phonegap.html).

This plugin supports apps running on iOS.
Requirements:
 - Cordova 5.0.0+, Cordova Android 4.0.0+, and Cordova iOS 3.8.0+
 - [GCM Setup](http://docs.urbanairship.com/platform/android.html#gcm-setup) or [APNS Setup](http://docs.urbanairship.com/platform/ios.html#apple-setup)

## Contributing Code

This plugin is meant to work with AppGyver Steroids 3.1.0+.
This plugin is meant to work with Cordova 3.4.0+ and the latest version of the Urban Airship library.

### Differences to the original plugin

This plugin has been forked from the [official Urban Airship plugin](https://github.com/urbanairship/phonegap-ua-push).

Then rebased against the upstream UA plugin.


Differences to the original include:

* takeOff() must be explicitly called by the application.

* Plugin will be initialized only in those WebViews which have called takeOff(). The major difference is that Steroids has multiple WebViews where Cordova has only one.

* Push notifications are not enabled by default. This will allow the application to define when the user will be asked whether he wants to allow push notifications. The dialog will be presented when enablePush() is called the first time.


### Installation

1. Install this plugin to AppGyver build service and build a custom scanner.

2. Modify the www/config.{ios,android}.xml file to contain (replacing with your configuration settings):
        <preference name="com.urbanairship.production_app_key" value="Your production app key" />
        <preference name="com.urbanairship.production_app_secret" value="Your production app secret" />
        <preference name="com.urbanairship.in_production" value="true" />
        <preference name="com.urbanairship.gcm_sender" value="Android only: Your GCM sender id" />

  Note: Your application will always be in production mode, since AppGyver Build Service will give an adhoc build or a custom scanner.

3. If your app supports Android API < 14, then you have to manually instrument any Android Activities to
have proper analytics.

See [Instrumenting Android Analytics](http://docs.urbanairship.com/build/android_features.html#setting-up-analytics-minor-assembly-required).

### Usage:

A ```PushNotification``` object will be available in your application's global JavaScript namespace. See below for API documentation.

Please follow the AppGyver Push Notification Guide (#TODO: Link here) for information how to create relevant certificates and configure the AppGyver Build Service.

#### Basic Example

    // Register for any urban airship events
    document.addEventListener("urbanairship.registration", function (event) {
        if (event.error) {
            console.log('There was an error registering for push notifications')
        } else {
            console.log("Registered with ID: " + event.channelID)
        } 
    }, false)
    
    document.addEventListener("urbanairship.push", function (event) {
        console.log("Incoming push: " + event.message)
    }, false)

    // Set tags on a device, that you can push to
    UAirship.setTags(["loves_cats", "shops_for_games"], function () {
        UAirship.getTags(function (tags) {
            tags.forEach(function (tag) {
                console.log("Tag: " + tag)
            })
        })
    })

    // Set an alias, this lets you tie a device to a user in your system
    UAirship.setAlias("awesomeuser22", function () {
        UAirship.getAlias(function (alias) {
            console.log("The user formerly known as " + alias)
        })
    })

    // Enable user notifications (will prompt the user to accept push notifications)
    UAirship.setUserNotificationsEnabled(true, function (enabled) {
        console.log("User notifications are enabled! Fire away!")
    })

## Sample

#### isBackgroundLocationEnabled(callback)

*Callback arguments:* (Boolean enabled)

Indicates whether background location updates are enabled.

#### isInQuietTime(callback)

*Callback arguments:* (Boolean inQuietTime)

Indicates whether Quiet Time is currently in effect.

### Getters

#### getLaunchNotification(callback)

*Callback arguments:* (Boolean clear)

Returns the last notification that launched the application and takes a boolean to clear the notification or not.

#### getChannelID(callback)

*Callback arguments:* (String ID)

Get the push identifier for the device. The channel ID is used to send messages to the device for testing, and is the canonical identifier for the device in Urban Airship.

**Note:** iOS will always have a push identifier. Android will always have one once the application has had a successful registration.

#### getQuietTime(callback)

*Callback arguments:* (QuietTime currentQuietTime)

Get the current quiet time.

#### getTags(callback)

*Callback arguments:* (Array currentTags)

Get the current tags.

#### getAlias(callback)

*Callback arguments:* (String currentAlias)

Get the alias.

#### getNamedUser(callback)

*Callback arguments:* (String namedUser)

Get the named user ID.

#### getBadgeNumber(callback)
**Note:** iOS only

*Callback arguments:* (Int badgeNumber)

Get the current application badge number.

### Setters

#### setTags(Array tags, callback)

Set tags for the device.

#### setAlias(String alias, callback)

Set alias for the device.

#### setNamedUser(String namedUser, callback)

Set the named user ID for the device.

#### setSoundEnabled(Boolean enabled, callback)
**Note:** Android Only, iOS sound settings come in the push.

Set whether the device makes sound on push.

#### setVibrateEnabled(Boolean enabled, callback)
**Note:** Android Only

Set whether the device vibrates on push.

#### setQuietTimeEnabled(Boolean enabled, callback)

Set whether quiet time is on.

#### setQuietTime(QuietTime newQuietTime, callback)

Set the quiet time for the device.

#### setAnalyticsEnabled(Boolean enabled, callback)

Enables or disables analytics. Disabling analytics will delete any locally stored events and prevent any events from uploading. Features that depend on analytics being enabled may not work properly if it's disabled (reports, region triggers, location segmentation, push to local time).

#### setAutobadgeEnabled(Boolean enabled, callback)
**Note:** iOS only

Set whether the UA Auto badge feature is enabled.

#### setBadgeNumber(Int badge, callback)
**Note:** iOS only

Set the current application badge number.

#### resetBadge(callback)
**Note:** iOS only

Reset the badge number to zero.

#### clearNotifications(callback)
**Note:** Android only

Clears the notifications posted by the application.

### Location

#### recordCurrentLocation(callback)

Report the location of the device.

### Events

**Note:** If your application supports Android and it listens to any of the events, you should
start listening for events on both 'deviceReady' and 'resume' and stop listening for events on 'pause'.
This will prevent the events from being handled in the background.

### Incoming Push

Event:

    {
        message: <Alert Message>,
        extras: <Extras Dictionary>
    }

This event is triggered when a push notification is received.

    document.addEventListener('urbanairship.push', function(event) {
        alert(event.message);
    });


### Registration

Event:
    document.addEventListener('urbanairship.registration', function(event) {
        if (event.error) {
            console.log('There was an error registering for push notifications.');
        } else {
            console.log("Registered with ID: " + event.channelID);
        } 
    });
