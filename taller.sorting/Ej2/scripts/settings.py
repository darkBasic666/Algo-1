import os
from utils import listfiles

# Sources listadas manualmente
# sources = ['main', 'utils', 'utils2/utils2']

# Sources listadas automaticamente
sources = [f[:f.rfind('.')] for f in listfiles('.', '*.cpp')]

# Compilador
compiler = 'g++'

# Programa compilado
executable = './taller' if os.name == 'posix' else 'taller.exe'

# Parametros extra
extraParams = ['-std=c++0x']

