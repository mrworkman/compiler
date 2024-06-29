project(
    'dmc',
    'cpp',
    default_options : ['cpp_std=c++98']
)

add_project_arguments(
    language : 'cpp'
)

# Program entry is in nwc.cpp

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
        'msgtbl.h',
    ]
)

optabgen_exe = executable(
    'optabgen',
    'src/optabgen.cpp',
    include_directories: tk_includes,
    cpp_args: [
        '-D_WCHAR_T',
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
        'elxxx.h',
        'cdxxx.h',
        'optab.h',
        'debtab.h',
        'fltables.h',
        'tytab.h',
    ]
)

executable(
    'scppn',
    msgsx_tgt,
    optabgen_tgt,
    sources,
    include_directories: [
        tk_includes,
        include_directories('.'),
    ],
    cpp_args: [
        '-DSCPP',
        '-D_WCHAR_T',
        '-Wno-missing-braces',
        '-Wno-sometimes-uninitialized',
        '-Wno-unused-variable',
        '-Wno-unused-but-set-variable',
        '-w',
    ],
)

executable(
    'sppn',
    sources,
    msgsx_tgt,
    optabgen_tgt,
    include_directories: [
        tk_includes,
        include_directories('.'),
    ],
    cpp_args: [
        '-DSCPP',
        '-D_WCHAR_T',
        '-Wno-missing-braces',
        '-Wno-sometimes-uninitialized',
        '-Wno-unused-variable',
        '-Wno-unused-but-set-variable',
        '-w',
    ],
)
