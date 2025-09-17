add_rules("mode.debug", "mode.release")

if is_host("windows") or is_host("linux") then 
    add_requires("tinycc")
end

target("xdgbasedir")
    set_kind("shared")
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
    if is_host("windows") or is_host("linux") then 
        set_toolchains("@tinycc")
     else
        set_toolchains("@clang")
    end


target("libsukanku")
    set_kind("shared")
    add_files("libsukanku/*.c")
    add_deps("xdgbasedir")
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

