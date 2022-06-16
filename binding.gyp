{
  "targets": [
    {
      "target_name": "ComputingNode",
      "sources": [
        "./src/main.cpp",
        "./src/nan_algorithm.cpp",
        "./src/nan_matrix.cpp",
        "./src/nan_sorting.cpp",
        "./src/algorithm.cpp",
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ],
}