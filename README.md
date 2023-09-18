# cpp-ext-with-numpy

## Installation

Create an environment using `conda` or `mamba` using the `environment.yaml` file, and
activate it.

```bash
mamba env create --file environment.yaml
mamba activate cpp-ext-with-numpy
```

We will use `pip` to install the rest of the project's dependencies.

```bash
pip install --force-reinstall .[dev,test]
```

Any changes to the package requires a re-installation, since we are making a C++
extension. After making changes, run the above command again.

## Development

Ensure that `pre-commit` is installed by running the following.

```bash
pre-commit install
```

Any time you commit changes, the `pre-commit` hooks will run and ensure the commits
conform to the standards defined in the `.pre-commit-config.yaml` file.
