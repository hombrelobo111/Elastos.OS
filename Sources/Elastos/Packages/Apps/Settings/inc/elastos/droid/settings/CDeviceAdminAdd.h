//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_DROID_SETTINGS_CDEVICEADMINADD_H__
#define __ELASTOS_DROID_SETTINGS_CDEVICEADMINADD_H__

#include "Elastos.Droid.Os.h"
#include "Elastos.Droid.Widget.h"
#include "Elastos.CoreLibrary.Utility.h"
#include "_Elastos_Droid_Settings_CDeviceAdminAdd.h"
#include "elastos/droid/app/Activity.h"
#include "elastos/droid/os/RemoteCallback.h"
#include <elastos/core/Runnable.h>

using Elastos::Droid::App::Activity;
using Elastos::Droid::App::IAppOpsManager;
using Elastos::Droid::App::IDialog;
using Elastos::Droid::App::Admin::IDeviceAdminInfo;
using Elastos::Droid::App::Admin::IDevicePolicyManager;
using Elastos::Droid::Content::IDialogInterface;
using Elastos::Droid::Content::IDialogInterfaceOnClickListener;
using Elastos::Droid::Os::IBundle;
using Elastos::Droid::Os::IHandler;
using Elastos::Droid::Os::RemoteCallback;
using Elastos::Droid::View::IView;
using Elastos::Droid::View::IViewOnClickListener;
using Elastos::Droid::View::IViewGroup;
using Elastos::Droid::Widget::IButton;
using Elastos::Droid::Widget::IImageView;
using Elastos::Droid::Widget::ITextView;
using Elastos::Core::Runnable;
using Elastos::Utility::IArrayList;
using Elastos::Utility::IList;

namespace Elastos {
namespace Droid {
namespace Settings {

CarClass(CDeviceAdminAdd)
    , public Activity
{
private:
    class ViewOnClickListener
        : public Object
        , public IViewOnClickListener
    {
    public:
        TO_STRING_IMPL("CDeviceAdminAdd::ViewOnClickListener");

        CAR_INTERFACE_DECL()

        ViewOnClickListener(
            /* [in] */ CDeviceAdminAdd* host,
            /* [in] */ Int32 id);

        ~ViewOnClickListener();

        CARAPI OnClick(
            /* [in] */ IView* v);

    private:
        CDeviceAdminAdd* mHost;
        Int32 mId;
    };

    class MyRemoteCallback
        : public RemoteCallback
    {
    public:
        TO_STRING_IMPL("CDeviceAdminAdd::MyRemoteCallback")

        MyRemoteCallback();

        CARAPI constructor(
            /* [in] */ IHandler* handler,
            /* [in] */ CDeviceAdminAdd* host);

    protected:
        //@Override
        CARAPI_(void) OnResult(
            /* [in] */ IBundle* bundle);

    private:
        CDeviceAdminAdd* mHost;
    };

    class MyRunnable
        : public Runnable
    {
    public:
        TO_STRING_IMPL("CDeviceAdminAdd::MyRunnable")

        MyRunnable(
            /* [in] */ CDeviceAdminAdd* host);

        //@Override
        CARAPI Run();

    private:
        CDeviceAdminAdd* mHost;
    };

    class DialogInterfaceOnClickListener
        : public Object
        , public IDialogInterfaceOnClickListener
    {
    public:
        TO_STRING_IMPL("CDeviceAdminAdd::DialogInterfaceOnClickListener")

        CAR_INTERFACE_DECL()

        DialogInterfaceOnClickListener(
            /* [in] */ CDeviceAdminAdd* host);

        CARAPI OnClick(
            /* [in] */ IDialogInterface* dialog,
            /* [in] */ Int32 which);

    private:
        CDeviceAdminAdd* mHost;
    };

public:
    CAR_OBJECT_DECL()

    CDeviceAdminAdd();

    virtual ~CDeviceAdminAdd();

    CARAPI constructor();

protected:
    //@Override
    CARAPI OnCreate(
        /* [in] */ IBundle* icicle);

    //@Override
    CARAPI OnResume();

    //@Override
    CARAPI OnPause();

    //@Override
    CARAPI_(AutoPtr<IDialog>) OnCreateDialog(
        /* [in] */ Int32 id,
        /* [in] */ IBundle* args);

    virtual CARAPI_(void) AddAndFinish();

    virtual CARAPI_(void) ContinueRemoveAction(
        /* [in] */ ICharSequence* msg);

    static CARAPI_(void) SetViewVisibility(
        /* [in] */ IArrayList* views, //ArrayList<View>
        /* [in] */ Int32 visibility);

    virtual CARAPI_(void) UpdateInterface();

    virtual CARAPI_(void) ToggleMessageEllipsis(
        /* [in] */ IView* v);

    virtual CARAPI_(Int32) GetEllipsizedLines();

protected:
    static const String TAG;

    static const Int32 DIALOG_WARNING;

    AutoPtr<IHandler> mHandler;

    AutoPtr<IDevicePolicyManager> mDPM;
    AutoPtr<IAppOpsManager> mAppOps;
    AutoPtr<IDeviceAdminInfo> mDeviceAdmin;
    AutoPtr<ICharSequence> mAddMsgText;
    String mProfileOwnerName;

    AutoPtr<IImageView> mAdminIcon;
    AutoPtr<ITextView> mAdminName;
    AutoPtr<ITextView> mAdminDescription;
    AutoPtr<ITextView> mAddMsg;
    AutoPtr<ITextView> mProfileOwnerWarning;
    AutoPtr<IImageView> mAddMsgExpander;
    Boolean mAddMsgEllipsized;
    AutoPtr<ITextView> mAdminWarning;
    AutoPtr<IViewGroup> mAdminPolicies;
    AutoPtr<IButton> mActionButton;
    AutoPtr<IButton> mCancelButton;

    // final ArrayList<View> mAddingPolicies = new ArrayList<View>();
    AutoPtr<IArrayList> mAddingPolicies;
    // final ArrayList<View> mActivePolicies = new ArrayList<View>();
    AutoPtr<IArrayList> mActivePolicies;

    Boolean mAdding;
    Boolean mRefreshing;
    Boolean mWaitingForRemoveMsg;
    Boolean mAddingProfileOwner;
    Int32 mCurSysAppOpMode;
    Int32 mCurToastAppOpMode;

private:
    static const Int32 MAX_ADD_MSG_LINES_PORTRAIT;
    static const Int32 MAX_ADD_MSG_LINES_LANDSCAPE;
    static const Int32 MAX_ADD_MSG_LINES;
};

} // namespace Settings
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_SETTINGS_CDEVICEADMINADD_H__