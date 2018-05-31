cxx_binary (
    headers = subdir_glob([
        ('include/generic', '**/*.h'),
    ]),
    name = 'connect',
    platform_headers = [
        ('^linux.*', subdir_glob([
            ('include/os_dependent/linux', '**/*.h'),
        ])),
        ('^windows.*', subdir_glob([
            ('include/os_dependent/windows', '**/*.h'),
        ])),
    ],
    platform_compiler_flags = [
        ('^linux.*', ['--std=c++17']),
        ('^windows.*', ['/D "_PROJECT_SUPPORT_WINDOWS_"']),
    ],
    platform_linker_flags = [
        ('^windows.*', [
            '"kernel32.lib"',
            '"user32.lib"',
            '"gdi32.lib"',
            '/SUBSYSTEM:WINDOWS',
            '/ENTRY:mainCRTStartup'
        ]),
    ],
    platform_srcs = [
        ('^linux.*', glob([
            'src/os_dependent/linux/**/*.cpp',
        ])),
        ('^windows.*', glob([
            'src/os_dependent/windows/**/*.cpp',
        ])),
    ],
    srcs = glob([
        'src/generic/**/*.cpp',
    ]),
)
