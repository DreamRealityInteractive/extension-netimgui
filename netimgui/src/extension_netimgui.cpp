#define LIB_NAME "NetImGui"
#define MODULE_NAME "netimgui"

//#include "imgui/imgui.h"
//#include "imgui/imconfig.h"
#include "netimgui/NetImgui_Api.h"

#include <dmsdk/sdk.h>

// ----------------------------
// ----- NETIMGUI -----------------
// ----------------------------

static int netimgui_ConnectToApp(lua_State *L)
{
    DM_LUA_STACK_CHECK(L, 0);
    //imgui_NewFrame();
    const char* client_name = luaL_checkstring(L, 1);
    const char* server_host = luaL_checkstring(L, 2);
    NetImgui::ConnectToApp(client_name, server_host);
    return 0;
}

static int netimgui_ConnectFromApp(lua_State *L)
{
    DM_LUA_STACK_CHECK(L, 0);
    //imgui_NewFrame();
    const char* client_name = luaL_checkstring(L, 1);
    NetImgui::ConnectFromApp(client_name);
    return 0;
}

static int netimgui_Disconnect(lua_State *L)
{
    DM_LUA_STACK_CHECK(L, 0);
    //imgui_NewFrame();
    NetImgui::Disconnect();
    return 0;
}

static int netimgui_IsConnected(lua_State *L)
{
    DM_LUA_STACK_CHECK(L, 1);
    //imgui_NewFrame();
    bool is_connected = NetImgui::IsConnected();
    lua_pushboolean(L, is_connected);
    return 1;
}


// Functions exposed to Lua
static const luaL_reg Module_methods[] =
{
    {"connect_from_app", netimgui_ConnectFromApp},
    {"connect_to_app", netimgui_ConnectToApp},
    {"disconnect", netimgui_Disconnect},
    {"is_connected", netimgui_IsConnected},
    {0, 0}
};


static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);

    // Register lua names
    luaL_register(L, MODULE_NAME, Module_methods);
   
    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeDefoldNetImGui(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeDefoldNetImGui(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    NetImgui::Startup();
    
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeDefoldNetImGui(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeDefoldNetImGui(dmExtension::Params* params)
{
    dmLogInfo("FinalizeDefoldNetImGui");
    NetImgui::Shutdown();
    return dmExtension::RESULT_OK;
}

dmExtension::Result OnUpdateDefoldNetImGui(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

void OnEventDefoldNetImGui(dmExtension::Params* params, const dmExtension::Event* event)
{
    switch(event->m_Event)
    {
        case dmExtension::EVENT_ID_ACTIVATEAPP:
        //dmLogInfo("OnEventDefoldImGui - EVENT_ID_ACTIVATEAPP\n");
        break;
        case dmExtension::EVENT_ID_DEACTIVATEAPP:
        //dmLogInfo("OnEventDefoldImGui - EVENT_ID_DEACTIVATEAPP\n");
        break;
        case dmExtension::EVENT_ID_ICONIFYAPP:
        //dmLogInfo("OnEventDefoldImGui - EVENT_ID_ICONIFYAPP\n");
        break;
        case dmExtension::EVENT_ID_DEICONIFYAPP:
        //dmLogInfo("OnEventDefoldImGui - EVENT_ID_DEICONIFYAPP\n");
        break;
        default:
        //dmLogWarning("OnEventDefoldImGui - Unknown event id\n");
        break;
    }
}

DM_DECLARE_EXTENSION(DefoldNetImGui, LIB_NAME, AppInitializeDefoldNetImGui, AppFinalizeDefoldNetImGui, InitializeDefoldNetImGui, OnUpdateDefoldNetImGui, OnEventDefoldNetImGui, FinalizeDefoldNetImGui)
