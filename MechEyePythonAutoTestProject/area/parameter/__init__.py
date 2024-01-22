import os
import sys
current_dir = os.path.dirname(__file__)
area_dir = os.path.dirname(current_dir)
project_dir = os.path.dirname(area_dir)
sys.path.append(project_dir)