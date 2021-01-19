## To use

- `yarn`
- `yarn build`
- `yarn watch` (requires watchexec)
- open `index.html` (no server required)

# My ideal ReScript monorepo

The goal is to run a single `bsb` from the project root and have everything Just Work (tm).

This repository leverages ReScript pinned packages support. The setup:

- yarn workspace-based monorepo (this ensures there are no secondary `node_modules` folders in the packages which might confuse `bsb`)
- packages are listed under `bs-dependencies` and `pinned-dependencies`, which works because the yarn workspace creates symlinks to each source package in `node_modules`
- `yarn build` compiles and bundles

As of 8.4.2-dev.1 this is considered ready for use. However do note that interface modifications, no matter how small, will still trigger a forest of rebuilds. For example changing `ExampleStyles.re` in `b` is a contained rebuild as expected, but changing `ExampleStyles.rei` causes a complete rebuild of package `c` even though `c` only uses the `Examples` module from `b`, not `ExampleStyles`.

In a perfect scenario `bsb` would track dependencies at a more granular level, to rebuild based on interface contents rather than simple file timestamps, as it does when the same structure is modelled as a flat namespace with a single `bsconfig.json`.

### Source
Heavily modified from the ReasonReact Template.