project(
    'dmc',
    'c', 'd'
)

add_project_arguments(
    '-DSCPP',

    # Despite all of the source files ending in .c, they
    # are in fact meant to be compiled as C++.
    '-xc++',

    # '-I../src/tk',
    # '-I../src/ntdllshell/include',

    # Meson complains if the language is set to 'cpp', because
    # it insists .c files must actually be C 🙄
    language : 'c'
)

# dmc.exe entry is in nwc.c

subdir('src')
tk_includes = include_directories('src/tk')

msgsx_exe = executable(
    'msgsx',
    'src/msgsx.c',
    include_directories: tk_includes,
    c_args: [
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
        'msgs2.c',
        'msgs2.d',
    ]
)

optabgen_exe = executable(
    'optabgen',
    'src/optabgen.c',
    msgsx_tgt,
    include_directories: tk_includes,
    c_args: [
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
    optabgen_tgt,
    include_directories: tk_includes,
    c_args: [
        '-Wno-missing-braces',
        '-Wno-sometimes-uninitialized',
        '-Wno-unused-variable',
        '-Wno-unused-but-set-variable',
        '-w',
    ]
)