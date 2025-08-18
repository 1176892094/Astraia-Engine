#include "Header.h"
#include <string>
#include <objc/objc.h>
#include <objc/message.h>
#include <objc/NSObjCRuntime.h>
#include "Source/Utils/PlatformUtils.h"

namespace Engine
{
  	std::optional<std::string>  FileDialogs::OpenFile(const char *filter)
    {
        id panelClass = (id) objc_getClass("NSOpenPanel");
        id panel = ((id(*)(id, SEL)) objc_msgSend)(panelClass, sel_registerName("openPanel"));

        ((void(*)(id, SEL, BOOL)) objc_msgSend)(panel, sel_registerName("setCanChooseFiles:"), YES);
        ((void(*)(id, SEL, BOOL)) objc_msgSend)(panel, sel_registerName("setCanChooseDirectories:"), NO);
        ((void(*)(id, SEL, BOOL)) objc_msgSend)(panel, sel_registerName("setAllowsMultipleSelection:"), NO);

        NSInteger result = ((NSInteger(*)(id, SEL)) objc_msgSend)(panel, sel_registerName("runModal"));

        if (result == 1)
        {
            id url = ((id(*)(id, SEL)) objc_msgSend)(panel, sel_registerName("URL"));
            id path = ((id(*)(id, SEL)) objc_msgSend)(url, sel_registerName("path"));
            const char *cstr = ((const char*(*)(id, SEL)) objc_msgSend)(path, sel_registerName("UTF8String"));
            return std::string(cstr);
        }

  	    return std::nullopt;
    }

  	std::optional<std::string> FileDialogs::SaveFile(const char *filter)
    {
        id panelClass = (id) objc_getClass("NSSavePanel");
        id panel = ((id(*)(id, SEL)) objc_msgSend)(panelClass, sel_registerName("savePanel"));

        NSInteger result = ((NSInteger(*)(id, SEL)) objc_msgSend)(panel, sel_registerName("runModal"));

        if (result == 1)
        {
            id url = ((id(*)(id, SEL)) objc_msgSend)(panel, sel_registerName("URL"));
            id path = ((id(*)(id, SEL)) objc_msgSend)(url, sel_registerName("path"));
            const char *cstr = ((const char*(*)(id, SEL)) objc_msgSend)(path, sel_registerName("UTF8String"));
            return std::string(cstr);
        }

  	    return std::nullopt;
    }
}
