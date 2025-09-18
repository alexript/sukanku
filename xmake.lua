add_rules("mode.debug", "mode.release")

if is_host("windows") or is_host("linux") then 
   add_requires("tinycc")
end

target("liblua")
    set_kind("shared")
    set_basename("lua")
    add_files("other/3rd_party/lua/src/*.c|lua.c|luac.c|onelua.c")
    add_headerfiles("other/3rd_party/lua/src/*.h", {prefixdir = "lua"})
    if is_host("windows") or is_host("linux") then 
       set_toolchains("@tinycc")
       add_sysincludedirs("other/3rd_party/lua/tcc_winapi")
    else
       set_toolchains("@clang")
    end

    add_defines("LUA_COMPAT_5_2", "LUA_COMPAT_5_1")
    if is_plat("linux", "bsd", "cross") then
       add_defines("LUA_USE_LINUX")
       add_defines("LUA_DL_DLOPEN")
    elseif is_plat("macosx", "iphoneos") then
       add_defines("LUA_USE_MACOSX")
       add_defines("LUA_DL_DYLD")
    elseif is_plat("windows", "mingw") then
       if is_kind("shared") then
	  add_defines("LUA_BUILD_AS_DLL", {public = true})
       end
    end

target("xdgbasedir")
    set_kind("static")
    add_files("other/xdg-basedir/*.c")
    if is_host("windows") or is_host("linux") then 
       set_toolchains("@tinycc")
    else
       set_toolchains("@clang")
    end


target("tools")
    set_kind("binary")
    add_files("tools/*.c")
    add_deps("xdgbasedir")
    add_deps("liblua")
    if is_host("windows") or is_host("linux") then 
       set_toolchains("@tinycc")
    else
       set_toolchains("@clang")
    end


target("libsukanku")
    set_kind("shared")
    set_basename("sukanku")
    add_files("libsukanku/*.c")
    add_deps("xdgbasedir")
    add_deps("liblua")
    if is_host("windows") or is_host("linux") then 
       set_toolchains("@tinycc")
    else
       set_toolchains("@clang")
    end

target("sukankud")
    set_kind("binary")
    add_files("sukankud/*.c")
    add_deps("libsukanku")
    if is_host("windows") or is_host("linux") then 
       set_toolchains("@tinycc")
    else
       set_toolchains("@clang")
    end

target("sukanku")
    set_kind("binary")
    add_files("sukanku/*.c")
    add_deps("libsukanku")
    if is_host("windows") or is_host("linux") then 
       set_toolchains("@tinycc")
    else
       set_toolchains("@clang")
    end

