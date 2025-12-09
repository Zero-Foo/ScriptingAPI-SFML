# ScriptingAPI

This library provides a lightweight API for scripting objects (defining behaviors, exporting functions to scripts, etc.). The goal is to simplify integrating a scripting engine into a C++ application to control project objects.

Status
------

This project is under active development. Many features are implemented, but the API may still change and parts of the code are experimental.

Planned Features
----------------

- Provide structures and interfaces to expose C++ objects to scripts.
- Allow registration of object functions and properties with a scripting engine.
- Include examples and integration code in the `exemple/` directory to demonstrate usage.

Repository Structure
--------------------

- `scripting-api/`: main source code (`include/`, `src/`).
- `exemple/`: example projects and usage demonstrations.
- `CMakeLists.txt`: top-level CMake configuration for building the project.

Build (example)
----------------

The project uses CMake. Example PowerShell commands to generate and build (Debug x64):

```powershell
mkdir build
cmake -S . -B build
cmake --build build --config <Debug|Release>
```

Usage
-----

See the headers in `scripting-api/include/` for the exposed interfaces. The examples in `exemple/` demonstrate how to export functions and manage scriptable objects.

Contributing
------------

- Contributions are welcome. Please open an issue to discuss major changes.
- Report bugs or unexpected behavior — the project is evolving.

Contact
-------

For questions or suggestions, open an issue on the repository.

---