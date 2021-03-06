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

//This file is autogenerated for
//    SelectFileDialog.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_SELECTFILEDIALOG_CALLBACK_DEC_HH
#define ELASTOS_SELECTFILEDIALOG_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_SelectFileDialog_nativeOnFileSelected(IInterface* caller,Handle64 nativeSelectFileDialogImpl,const String& filePath,const String& displayName);
    extern void Elastos_SelectFileDialog_nativeOnFileNotSelected(IInterface* caller,Handle64 nativeSelectFileDialogImpl);
    extern void Elastos_SelectFileDialog_InitCallback(Handle64 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Ui {
namespace Base {

struct ElaSelectFileDialogCallback
{
    void (*elastos_SelectFileDialog_selectFile)(IInterface* obj, ArrayOf<String>* fileTypes, Boolean capture, IInterface* window);
    AutoPtr<IInterface> (*elastos_SelectFileDialog_create)(Handle64 nativeSelectFileDialog);
};

void* SelectFileDialog::ElaSelectFileDialogCallback_Init()
{
    static ElaSelectFileDialogCallback sElaSelectFileDialogCallback;

    sElaSelectFileDialogCallback.elastos_SelectFileDialog_selectFile = &SelectFileDialog::SelectFile;
    sElaSelectFileDialogCallback.elastos_SelectFileDialog_create = &SelectFileDialog::Create;

    Elastos_SelectFileDialog_InitCallback((Handle64)&sElaSelectFileDialogCallback);
    return &sElaSelectFileDialogCallback;
}

static void* sPElaSelectFileDialogCallback = SelectFileDialog::ElaSelectFileDialogCallback_Init();

} // namespace Base
} // namespace Ui
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_SELECTFILEDIALOG_CALLBACK_DEC_HH
