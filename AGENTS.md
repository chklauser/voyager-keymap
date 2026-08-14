# Voyager keymap repository

- This combines the [Oryx/custom-QMK workflow](https://github.com/poulainpi/oryx-with-custom-qmk), per-layout customizations, and the [sm_td QMK user library](https://github.com/stasmarkin/sm_td). Follow those upstream projects by reference; do not duplicate their documentation here.
- Root directories named with an Oryx configuration ID are independent layouts. `e5Wax` is the default/current layout; `aZrxD` remains supported. Keep the multi-layout structure and do not change another layout unless the task calls for it.
- Layout customization lives in each layout's `config.h`, `keymap.c`, and `rules.mk`. Oryx refreshes generated files through `.github/workflows/fetch-and-build-layout.yml`, then merges the `oryx` branch into `main`.
- `e5Wax/sm_td.h` and `e5Wax/sm_td.c` vendor sm_td, with related setup in `e5Wax/config.h`, `keymap.c`, and `rules.mk`. Read the version/date header in the vendored files, then consult that exact upstream tag and its upgrade instructions before changing them.
- sm_td pipeline taps are intentionally disabled only for `KC_J` and `KC_K` because those keys participate in a `COMBO_ACTION`; retain that compatibility guard unless the combo behavior is revalidated.
- `qmk_firmware` is the ZSA QMK fork as a submodule. Treat it as build input and reference code; do not edit it unless explicitly requested. The workflow selects the Oryx-required `firmwareN` branch and may update the recorded submodule revision.
- This is a colocated Jujutsu repository. Use `jj` for version-control mutations and Git only for read-only inspection.
- Local firmware builds are not expected to work because their toolchain is intentionally absent. Use `scripts/build-and-archive` to dispatch, monitor, verify, and retain GitHub Actions builds. Pass `--run-id ID` to archive an existing run without spending runner minutes.
- Extracted firmware images belong outside the repository at `~/Dropbox/admin/voyager/<layout>/voyager-<YYYYMMDD>-<commit>.bin` (or the image's native extension). Never overwrite an existing archive.
