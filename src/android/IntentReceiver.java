package com.urbanairship.cordova;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.support.v4.content.LocalBroadcastManager;

import com.urbanairship.push.BaseIntentReceiver;
import com.urbanairship.push.PushMessage;
import com.urbanairship.cordova.UAirshipPlugin;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import android.util.Log;

public class IntentReceiver extends BaseIntentReceiver {
    private static final String TAG = "IntentReceiver";

    @Override
    protected void onChannelRegistrationSucceeded(Context context, String channelId) {
        Log.i(TAG, "Channel registration updated. Channel ID: " + channelId + ".");

        Intent intent = new Intent(UAirshipPlugin.ACTION_CHANNEL_REGISTRATION);
        LocalBroadcastManager.getInstance(context).sendBroadcast(intent);
    }

    @Override
    protected void onChannelRegistrationFailed(Context context) {
        Log.i(TAG, "Channel registration failed.");

        Intent intent = new Intent(UAirshipPlugin.ACTION_CHANNEL_REGISTRATION)
                .putExtra(UAirshipPlugin.EXTRA_ERROR, true);

        LocalBroadcastManager.getInstance(context).sendBroadcast(intent);
    }

    @Override
    protected void onPushReceived(Context context, PushMessage message, int notificationId) {
        Log.i(TAG, "Received push notification. Alert: " + message.getAlert() + ". Notification ID: " + notificationId);

        Intent intent = new Intent(UAirshipPlugin.ACTION_PUSH_RECEIVED)
                .putExtra(UAirshipPlugin.EXTRA_PUSH, message)
                .putExtra(UAirshipPlugin.EXTRA_NOTIFICATION_ID, notificationId);

        LocalBroadcastManager.getInstance(context).sendBroadcast(intent);
    }

    @Override
    protected void onBackgroundPushReceived(Context context, PushMessage message) {
        Log.i(TAG, "Received background push message: " + message);

        Intent intent = new Intent(UAirshipPlugin.ACTION_PUSH_RECEIVED)
                .putExtra(UAirshipPlugin.EXTRA_PUSH, message);

        LocalBroadcastManager.getInstance(context).sendBroadcast(intent);
    }

    @Override
    protected boolean onNotificationOpened(Context context, PushMessage message, int notificationId) {
        Log.i(TAG, "User clicked notification. Alert: " + message.getAlert());

        UAirshipPlugin.launchPushMessage = message;
        UAirshipPlugin.launchNotificationId = notificationId;

        return false;
    }

    @Override
    protected boolean onNotificationActionOpened(Context context, PushMessage message, int notificationId, String buttonId, boolean isForeground) {
        Log.i(TAG, "User clicked notification button. Button ID: " + buttonId + " Alert: " + message.getAlert());

        UAirshipPlugin.launchPushMessage = message;
        UAirshipPlugin.launchNotificationId = notificationId;

        return false;
    }
}
