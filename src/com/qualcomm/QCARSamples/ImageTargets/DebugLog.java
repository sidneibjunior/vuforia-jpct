/*==============================================================================
Copyright (c) 2010-2013 QUALCOMM Austria Research Center GmbH.
All Rights Reserved.

==============================================================================*/

package com.qualcomm.QCARSamples.ImageTargets;

import android.util.Log;

/** DebugLog is a support class for the QCAR samples applications.
 *
 *  Exposes functionality for logging.
 *
 * */

public class DebugLog
{
    private static final String LOGTAG = "QCAR";

    /** Logging functions to generate ADB logcat messages. */

    public static final void LOGE(String nMessage)
    {
        Log.e(LOGTAG, nMessage);
    }


    public static final void LOGW(String nMessage)
    {
        Log.w(LOGTAG, nMessage);
    }


    public static final void LOGD(String nMessage)
    {
        Log.d(LOGTAG, nMessage);
    }


    public static final void LOGI(String nMessage)
    {
        Log.i(LOGTAG, nMessage);
    }
}
