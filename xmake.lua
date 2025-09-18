add_rules("mode.debug", "mode.release")

if is_host("windows") or is_host("linux") then 
   add_requires("tinycc")
end

if is_host("windows") or is_host("linux") then 
   set_toolchains("@tinycc")
else
   set_toolchains("@clang")
end

if is_host("windows") then
   add_sysincludedirs("other/3rd_party/tcc_winapi")
end


target("liblua")
    set_kind("shared")
    set_basename("lua")
    add_files("other/3rd_party/lua/src/*.c|lua.c|luac.c|onelua.c")
    add_headerfiles("other/3rd_party/lua/src/*.h", {prefixdir = "lua"})
    add_includedirs("other/3rd_party/lua/src", {public = true})

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

target("libsukankurt")
    set_kind("static")
    set_basename("sukankurt")

    add_headerfiles("other/filesystem/*.h")
    add_includedirs("other/filesystem", {public = true})
    add_files("other/filesystem/*.c")

    add_headerfiles("other/environment/*.h")
    add_includedirs("other/environment", {public = true})
    add_files("other/environment/*.c")

    add_headerfiles("other/xdg-basedir/*.h")
    add_includedirs("other/xdg-basedir", {public = true})
    add_files("other/xdg-basedir/*.c")


target("tools")
    set_kind("binary")
    add_files("tools/*.c")
    add_deps("libsukankurt")
    add_deps("liblua")


target("libsukanku")
    set_kind("shared")
    set_basename("sukanku")
    add_files("libsukanku/*.c")
    add_deps("libsukankurt")
    add_deps("liblua")

target("sukankud")
    set_kind("binary")
    add_files("sukankud/*.c")
    add_deps("libsukanku")

target("sukanku")
    set_kind("binary")
    add_files("sukanku/*.c")
    add_deps("libsukanku")

