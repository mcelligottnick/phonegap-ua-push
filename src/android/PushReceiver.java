package com.urbanairship.phonegap;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

import com.urbanairship.push.BaseIntentReceiver;
import com.urbanairship.push.PushMessage;

public class PushReceiver extends BaseIntentReceiver {

    private static final String TAG = "IntentReceiver";

    @Override
    protected void onChannelRegistrationSucceeded(Context context, String channelId) {
        Log.i(TAG, "Channel registration updated. Channel ID:" + channelId + ".");

        PushNotificationPlugin.raiseRegistration(true, channelId);
    }

    @Override
    protected void onChannelRegistrationFailed(Context context) {
        Log.i(TAG, "Channel registration failed.");

        PushNotificationPlugin.raiseRegistration(false, null);
    }

    @Override
    protected void onPushReceived(Context context, PushMessage message, int notificationId) {
        Log.i(TAG, "Received push notification. Alert: " + message.getAlert() + ". Notification ID: " + notificationId);

        PushNotificationPlugin.raisePush(message, notificationId);
    }

    @Override
    protected void onBackgroundPushReceived(Context context, PushMessage message) {
        Log.i(TAG, "Received background push message: " + message);

        PushNotificationPlugin.raisePush(message, null);
    }

    @Override
    protected boolean onNotificationOpened(Context context, PushMessage message, int notificationId) {
        Log.i(TAG, "User clicked notification. Alert: " + message.getAlert());
        PushNotificationPlugin.incomingPush = message;
        PushNotificationPlugin.incomingNotificationId = notificationId;

        return false;
    }

    @Override
    protected boolean onNotificationActionOpened(Context context, PushMessage message, int notificationId, String buttonId, boolean isForeground) {
        Log.i(TAG, "User clicked notification button. Button ID: " + buttonId + " Alert: " + message.getAlert());
        return false;
    }
}
