import unittest
import settings

from subprocess import *
from glob import glob
from utils import listfiles


class Tp1TestCase(unittest.TestCase):

  def runTp(self, input, output):
    """Invoca al tp con input y output como parametros"""
    check_call([settings.executable, input, output] + settings.extraParams, stdin=None, stdout=PIPE, stderr=PIPE)

  def assertRun(self, inputPath, expectedPath, outputPath):
    """Ejecuta tp.exe, pasando como parametros inputPath y outputPath, y verifica que la salida generada coincida con el contenido del archivo en expectedPath"""
    #expected, actual = [], []
    expected, actual = dict(), dict()

    self.runTp(inputPath, outputPath)

    with open(expectedPath, 'r') as fexpected:
      fexpected.readline() # ignore line
      expected = [ str(x.strip('[]')) for x in fexpected.readline()[1:-1].split(',')]

    with open(outputPath, 'r') as factual:
      factual.readline() # ignore line
      actual = [ str(x).strip('[]') for x in factual.readline()[1:-1].split(',')]

    self.assertEqual(len(expected), len(actual), "Se esperaban {0} valores en la solucion pero se encontraron {1}".format(len(expected), len(actual)))
    for index, (a, e) in enumerate(zip(actual, expected)):
      self.assertEqual(a, e, msg="Se esperaba {0} en la linea {1} pero se encontro {2}".format(e,index+1,a))


def addTest(cls, inputPath, expectedPath, outputPath):
  """Registra un test nuevo dinamicamente"""
  def dynamicTest(self): self.assertRun(inputPath, expectedPath, outputPath)
  tname = inputPath.replace("\\", "_").replace("/", "_").replace(".in", "")
  setattr(cls, tname, dynamicTest)


# Para cada archivo .in en la carpeta tests o cualquier subcarpeta, registra un nuevo test dinamicamente, verificando que la salida tenga el mismo contenido que el archivo con igual nombre pero extension .expected
for fname in listfiles('tests', '*.in'):
  addTest(Tp1TestCase, fname, fname.replace(".in", ".expected"), fname.replace(".in", ".out"))
