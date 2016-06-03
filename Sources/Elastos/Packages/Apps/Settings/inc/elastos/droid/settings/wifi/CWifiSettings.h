
#ifndef __ELASTOS_DROID_SETTINGS_WIFI_CWIFISETTINGS_H__
#define __ELASTOS_DROID_SETTINGS_WIFI_CWIFISETTINGS_H__

#include "_Elastos_Droid_Settings_Wifi_CWifiSettings.h"
#include "elastos/droid/settings/wifi/WifiSettings.h"

namespace Elastos {
namespace Droid {
namespace Settings {
namespace Wifi {

CarClass(CWifiSettings)
    , public WifiSettings
{
public:
    CAR_OBJECT_DECL();
};

} // namespace Wifi
} // namespace Settings
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_SETTINGS_WIFI_CWIFISETTINGS_H__
