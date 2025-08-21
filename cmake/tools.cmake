macro (append_source path out)
    file (
            GLOB_RECURSE
            sources
            ${path}/*.h
            ${path}/*.hpp
            ${path}/*.c
            ${path}/*.cpp
            ${path}/*.s
    )

    list (APPEND ${out} ${sources})
endmacro()

macro (target_append_source target scope path)
    append_source(${path} sources)
    target_sources(${target} ${scope} ${sources})
endmacro()

macro (scan_folders path out)

    file (
            GLOB_RECURSE
            glob_all
            LIST_DIRECTORIES true
            ${path}/*
    )

    list (APPEND ${out} ${path})

    foreach(child ${glob_all})
        if (IS_DIRECTORY ${child})
            list (APPEND ${out} ${child})
        endif()
    endforeach()
endmacro()
