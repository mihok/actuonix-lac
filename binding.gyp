{
  "targets": [
    # {
    #   "target_name": "greet",
    #   "cflags!": [ "-fno-exceptions" ],
    #   "cflags_cc!": [ "-fno-exceptions" ],
    #   "sources": [
    #     "./src/greeting.cpp",
    #     "./src/index.cpp"
    #   ],
    #   "include_dirs": [
    #     "<!@(node -p \"require('node-addon-api').include_dir\")"
    #   ],
    #   'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    # },
    {
      "target_name": "lac",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./src/lac.cpp"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include_dir\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}