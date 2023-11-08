project(
    'dmc',
    'cpp', 'd',
)

add_project_arguments(
    '-DSCPP',
    language : 'cpp'
)

# dmc.exe entry is in nwc.cpp

subdir('src')
tk_includes = include_directories('src/tk')

msgsx_exe = executable(
    'msgsx',
    'src/msgsx.cpp',
    include_directories: tk_includes,
    cpp_args: [
        '-Wno-invalid-source-encoding',
        '-Wno-unknown-escape-sequence',
    ]
)

msgsx_tgt = custom_target(
    'msgsx_tgt',
    build_by_default: true,
    command: [
        msgsx_exe
    ],
    output: [
        'msgs2.h',
        'msgs2.cpp',
        'msgs2.d',
    ]
)

optabgen_exe = executable(
    'optabgen',
    'src/optabgen.cpp',
    msgsx_tgt,
    include_directories: tk_includes,
    cpp_args: [
        '-Wno-missing-braces',
        '-Wno-char-subscripts',
    ],
)

optabgen_tgt = custom_target(
    'optabgen_tgt',
    build_by_default: true,
    command: [
        optabgen_exe
    ],
    output: [
        'elxxx.c',
        'cdxxx.c',
        'optab.c',
        'debtab.c',
        'fltables.c',
        'tytab.c',
    ]
)

executable(
    'dmc',
    sources,
    msgsx_tgt,
    # optabgen_tgt,
    include_directories: [
        tk_includes,
        x11_includes
    ],
    cpp_args: [
        '-Wno-missing-braces',
        '-Wno-sometimes-uninitialized',
        '-Wno-unused-variable',
        '-Wno-unused-but-set-variable',
        '-w',
    ],
)