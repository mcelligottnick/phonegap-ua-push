/*
 Copyright 2009-2013 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binaryform must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided withthe distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>
#import "UAPush.h"

@interface UAirshipPlugin : CDVPlugin <UARegistrationDelegate, UAPushNotificationDelegate>

/**
 * Enables or disables user push notifications.
 *
 * Expected arguments: Boolean
 *
 * @param command The cordova command.
 */
- (void)setUserNotificationsEnabled:(CDVInvokedUrlCommand*)command;

/**
 * Checks if user push notifications are enabled or not.
 *
 * @param command The cordova command.
 */
- (void)isUserNotificationsEnabled:(CDVInvokedUrlCommand*)command;

/**
 * Returns the last notification that launched the application.
 *
 * Expected arguments: Boolean - `YES` to clear the notification.
 *
 * @param command The cordova command.
 */
- (void)getLaunchNotification:(CDVInvokedUrlCommand*)command;

/**
 * Returns the channel ID.
 *
 * @param command The cordova command.
 */
- (void)getChannelID:(CDVInvokedUrlCommand*)command;

/**
 * Returns the tags as an array.
 *
 * @param command The cordova command.
 */
- (void)getTags:(CDVInvokedUrlCommand*)command;

/**
 * Sets the tags.
 *
 * Expected arguments: An array of Strings
 *
 * @param command The cordova command.
 */
- (void)setTags:(CDVInvokedUrlCommand*)command;

/**
 * Returns the alias.
 *
 * @param command The cordova command.
 */
- (void)getAlias:(CDVInvokedUrlCommand*)command;

/**
 * Sets the alias.
 *
 * Expected arguments: String
 *
 * @param command The cordova command.
 */
- (void)setAlias:(CDVInvokedUrlCommand*)command;

/**
 * Returns the current badge number.
 *
 * @param command The cordova command.
 */
- (void)getBadgeNumber:(CDVInvokedUrlCommand*)command;

/**
 * Enables or disables autobadging. Defaults to `NO`.
 *
 * Expected arguments: Boolean
 *
 * @param command The cordova command.
 */
- (void)setAutobadgeEnabled:(CDVInvokedUrlCommand*)command;

/**
 * Sets the badge number.
 *
 * Expected arguments: Number
 *
 * @param command The cordova command.
 */
- (void)setBadgeNumber:(CDVInvokedUrlCommand*)command;

/**
 * Clears the badge.
 *
 * @param command The cordova command.
 */
- (void)resetBadge:(CDVInvokedUrlCommand*)command;

/**
 * Sets the named user ID.
 *
 * Expected arguments: String
 *
 * @param command The cordova command.
 */
- (void)setNamedUser:(CDVInvokedUrlCommand*)command;

/**
 * Returns the named user ID.
 *
 * Expected arguments: String
 *
 * @param command The cordova command.
 */
- (void)getNamedUser:(CDVInvokedUrlCommand*)command;

/**
 * Enables or disbales quiet time.
 *
 * Expected arguments: Boolean
 *
 * @param command The cordova command.
 */
- (void)setQuietTimeEnabled:(CDVInvokedUrlCommand*)command;

/**
 * Checks if quiet time is currently enabled.
 *
 * @param command The cordova command.
 */
- (void)isQuietTimeEnabled:(CDVInvokedUrlCommand*)command;

/**
 * Sets the queit time.
 *
 * Expected arguments: Number - start hour, Number - start minute,
 * Number - end hour, Number - end minute
 *
 * @param command The cordova command.
 */
- (void)setQuietTime:(CDVInvokedUrlCommand*)command;

/**
 * Returns the queit time as an object with the following:
 * "startHour": Number,
 * "startMinute": Number,
 * "endHour": Number,
 * "endMinute": Number
 *
 * @param command The cordova command.
 */
- (void)getQuietTime:(CDVInvokedUrlCommand*)command;

/**
 * Checks if the device is currently in quiet time.
 *
 * @param command The cordova command.
 */
- (void)isInQuietTime:(CDVInvokedUrlCommand*)command;

/**
 * Sets the user notification types. Defaults to all notification types.
 *
 * Expected arguments: Number - bitmask of the notification types
 *
 * @param command The cordova command.
 */
- (void)setNotificationTypes:(CDVInvokedUrlCommand*)command;

/**
 * Enables or disables analytics.
 *
 * Disabling analytics will delete any locally stored events
 * and prevent any events from uploading. Features that depend on analytics being
 * enabled may not work properly if it's disabled (reports, region triggers,
 * location segmentation, push to local time).
 *
 * Expected arguments: Boolean
 *
 * @param command The cordova command.
 */
- (void)setAnalyticsEnabled:(CDVInvokedUrlCommand*)command;

/**
 * Checks if analytics is enabled or not.
 *
 * @param command The cordova command.
 */
- (void)isAnalyticsEnabled:(CDVInvokedUrlCommand*)command;

/**
 * Enables or disables location.
 *
 * Expected arguments: Boolean
 *
 * @param command The cordova command.
 */
- (void)setLocationEnabled:(CDVInvokedUrlCommand*)command;

/**
 * Checks if location is enabled or not.
 *
 * @param command The cordova command.
 */
- (void)isLocationEnabled:(CDVInvokedUrlCommand*)command;

/**
 * Enables or disables background location.
 *
 * Expected arguments: Boolean
 *
 * @param command The cordova command.
 */
- (void)setBackgroundLocationEnabled:(CDVInvokedUrlCommand*)command;

/**
 * Checks if background location is enabled or not.
 *
 * @param command The cordova command.
 */
- (void)isBackgroundLocationEnabled:(CDVInvokedUrlCommand*)command;

/**
 * Records the current location.
 *
 * @param command The cordova command.
 */
- (void)recordCurrentLocation:(CDVInvokedUrlCommand*)command;

/**
 * Runs an Urban Airship action. An object will be returned with
 * the following:
 * "error": String,
 * "value": *
 *
 * Expected arguments: String - action name, * - the action value
 *
 * @param command The cordova command.
 */
- (void)runAction:(CDVInvokedUrlCommand*)command;

/**
 * Registers the channel listener. Any channel registration updates will
 * be sent to the command's callbackID.
 *
 * @param command The cordova command.
 */
- (void)registerChannelListener:(CDVInvokedUrlCommand*)command;

/**
 * Registers the channel listener. Any channel registration updates will
 * be sent to the command's callbackID.
 *
 * @param command The cordova command.
 */
- (void)registerPushListener:(CDVInvokedUrlCommand*)command;


@end