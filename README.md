# Triangle — CS:GO Trainer

Triangle is a Windows desktop trainer for the legacy 32-bit Counter-Strike: Global Offensive client. It provides aim and trigger controls, visual overlays, weapon and knife skin selection, and miscellaneous movement options through a four-tab interface.

## Technology

- Visual C++ / C++/CLI, Windows Forms, and .NET Framework 4.8.
- Native Win32 APIs for process access, module discovery, input, and drawing.
- Windows GDI for overlays; System.Drawing for the managed UI.
- A shared charcoal-grey theme and Segoe UI fonts, including ClearType GDI text.
- Visual Studio 2026, MSVC v145, and a Windows 10/11 SDK.

## Build and run

Install Visual Studio's **Desktop development with C++** workload, **C++/CLI support for v145**, a Windows SDK, and the **.NET Framework 4.8 targeting pack**. Open `app.sln` and select **Debug | x86** or **Release | x86**.

From a Visual Studio Developer PowerShell:

```powershell
msbuild app.sln /t:Build /p:Configuration=Debug /p:Platform=x86
msbuild app.sln /t:Build /p:Configuration=Release /p:Platform=x86
```

Executables are written to `build/Win32/Debug/app.exe` and `build/Win32/Release/app.exe`. Intermediate files stay under `build/obj`. The solution uses x86 because the legacy process addresses and native stubs are 32-bit; the previous x64 configurations were not a supported port.

Run the executable normally to open the trainer and wait for the legacy game window. To check UI construction without starting game workers or attaching to a process:

```powershell
& ./build/Win32/Debug/app.exe --smoke-test
```

This opens each tab, saves `smoke-0.png` through `smoke-3.png` beside the executable, and exits.

## Source layout

| Files | Responsibility |
| --- | --- |
| `app/MyForm.cpp` | STA entry point and UI smoke test |
| `app/MyForm.h` | Form declarations and controls |
| `app/MyForm.Layout.cpp` | Control creation and page assembly |
| `app/MyForm.*Page.cpp` | Named builders for the four pages |
| `app/MyForm.Events.cpp` | UI event handlers |
| `app/MyForm.Runtime.cpp` | Initialization, skin lists, worker entry points |
| `app/Theme.*` | Shared UI colors and typography |
| `app/UiSettings.*` | Legacy shared UI settings, defined once |
| `app/features/` | Process access, aim, glow, GDI overlay, skins, utilities, offset scanning |
| `app/Offsets.*`, `app/SkinId.*`, `app/ItemDefinition.h` | Offset storage and item catalogs |

Feature headers declare interfaces; implementation belongs in `.cpp` files. Process and drawing objects own their native handles. Catalogs are read-only, and mutable shared data has one definition rather than being instantiated by every header consumer. Visual Studio filters group UI, feature, and data files.

## Validation and limitations

The refactor was built in Debug and Release x86 and checked with the four-tab UI smoke test. Existing compiler warnings remain in legacy feature code. Game interaction was not validated: offsets, signatures, and behavior still target historical CS:GO, not Counter-Strike 2. Glove controls remain the original placeholder UI. Shared settings and legacy worker threading remain areas for a future behavioral redesign.
