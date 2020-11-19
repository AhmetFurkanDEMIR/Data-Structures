from flask import render_template, Flask, flash, request
from ctypes import *
from multiprocessing.pool import ThreadPool

app = Flask(__name__)
app.secret_key = b'_5#y2L"F4Q8z\n\xec]/'

def runa(text0, text1):

	adder = CDLL('./adder.so')

	adder.run.restype = c_char_p
	a = adder.run(c_double(text0),text1)

	a = str(a)
	a = a.split("'")

	return a[1]


@app.route("/")
def main():

    return render_template("index.html")

@app.route("/run",methods = ['GET', 'POST'])
def run():

	if request.method == "POST":
		text0 = request.form['name0']
		text1 = request.form['name1']

		try:

			text0 = float(text0)

		except:

			flash("The number to be converted to binary must have a float data type or an int data type.")
			return render_template("index.html")

		try:

			text1 = int(text1)

		except:

			flash("Number precision must have data type int.")
			return render_template("index.html")

		if text1<1:

			flash("Number precision cannot be less than 1.")
			return render_template("index.html")

		kn = 0

		if text0 < float(0):

			text0=text0*(-1)
			kn = 1

		pool = ThreadPool(processes=1)
		async_result = pool.apply_async(runa, (text0, text1))

		result = async_result.get()

		result+="₂"
		text0 = str(text0)

		text0 = text0 + "₁₀"


		return render_template("result.html", text0=text0, result=result)


if __name__ == "__main__":

    app.run(debug=True)