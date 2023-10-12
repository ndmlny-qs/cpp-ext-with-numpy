#include <Python.h>

#include <cmath>

inline PyObject *cosine(PyObject *self, PyObject *args) {
  double input;
  if (!PyArg_ParseTuple(args, "d", &input)) {
    return NULL;
  }

  double output = cos(input);
  return PyFloat_FromDouble(output);
}
