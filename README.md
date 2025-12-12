# SOMIM

![License](https://img.shields.io/github/license/AlphaAn/somim)  
![Language](https://img.shields.io/github/languages/top/AlphaAn/somim)

SOMIM is an open-source program code that implements a Search for Optimal Measurements by using an Iterative Method. For a given set of statistical operators, SOMIM finds the POVMs that maximize the accessed information, and thus determines the accessible information and one or all of the POVMs that retrieve it. The maximization procedure is a steepest-ascent method that follows the gradient in the POVM space, and also uses conjugate gradients for speed-up.

SOMIM was originally written in the early 2000s by K. L. Lee, J. W. Shang, W. K. Chua, S. Y. Looi, and B.-G. Englert. More recently, we (K. D. A. Thai and M. Dall'Arno) replaced the graphical user interface of the original software with interfaces for GNU Octave and Python.

We also provide several applications related to the investigation and empirical testing of a conjecture by A. Keil.

## 📂 Repository Structure

The project is structured to separate the core SOMIM algorithm from the usability interfaces and research applications:

* **`core/`**: Contains the original C++ library source code (`libsomim.cpp`, `libsomim.h`) implementing the SOMIM algorithm.
* **`python/`**: The Python interface (`somim_wrapper.cpp`) that acts as a wrapper, enabling the execution of the C++ core from Python scripts and environments.
* **`octave/`**: The interface files (`accinfo.cpp`) used to integrate the SOMIM algorithm into the GNU Octave environment.
* **`experiments/`**: Jupyter Notebooks (e.g., `Project_Research_on_Mutual_Information.ipynb`) where our research, analysis, and applications, including work on Keil's Conjecture, are performed.

## 🚀 Installation & Setup

### Prerequisites
* Python 3.8 or higher  
* C++ Compiler 
* Git  

### 1. Clone the Repository
```bash
git clone https://github.com/AlphaAn/somim.git
cd somim
```

### 2. Set up a Python Virtual Environment
It is recommended to use a virtual environment to keep dependencies clean.

```bash
# Windows
python -m venv venv
venv\Scripts\activate

# macOS / Linux
python3 -m venv venv
source venv/bin/activate
```

### 3. Install Dependencies
Install the required Python libraries listed in `requirements.txt`.

```bash
pip install -r requirements.txt
```

### 4. Build and Install the Python Wrapper
To use the C++ core in Python, compile and install the package located in the `python/` directory.

```bash
cd python
pip install .
```

*Note: This will compile `somim_wrapper.cpp` and install the package into your current environment.*

## 💻 Usage

### Python
Once installed, you can import the library:

```python
import somim_module

# Refer to experiments/SOMIM_Demo.ipynb for usage
```

### Jupyter Notebooks
Use the experiments folder to run and modify the research notebooks:

```bash
jupyter notebook experiments/
```

## 📜 License

This project is licensed under the **GPL-3.0 License**. See the `LICENSE` file for details.
