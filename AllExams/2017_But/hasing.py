
data = []

# struct, data sakladığım listeler.
def init(data,x):

	for i in range(0,x):

		data.append([])

	return data


# python 3.9
def hasing(data,x):
	
	# karekterlerin ascii toplamini tatacagim degisken
	y = 0

	#gelen stringin tüm karekterleri
	for i in x:

		y+= ord(i) #ascii hale cevirdim

	key = y%10 #toplam degiskeninin 30 ile modunu alarak, tum stringleri 0 ile 30 arasındaki degere hashledim.

	
	data[key].append(x)

	return data

def ara(data, x):

	knt = None

	# karekterlerin ascii toplamini tatacagim degisken
	y = 0

	#gelen stringin tüm karekterleri
	for i in x:

		y+= ord(i) #ascii hale cevirdim

	key = y%10 #toplam degiskeninin 30 ile modunu alarak, tum stringleri 0 ile 30 arasındaki degere hashledim.

	for i in data[key]:

		if i==x:
			
			knt = True
			print("Veri bulundu : ",x)
			break	

	if knt==None:

		print("Bulamadim")

def delete(data, x):

	knt = None

	# karekterlerin ascii toplamini atatacagim degisken
	y = 0

	#gelen stringin tüm karekterleri
	for i in x:

		y+= ord(i) #ascii hale cevirdim

	key = y%10 #toplam degiskeninin 30 ile modunu alarak, tum stringleri 0 ile 30 arasındaki degere hashledim.

	j=0

	for i in data[key]:

		if i==x:
			
			knt = True
			del data[key][j]
			break

		j+=1

	if knt==None:

		print("Bulamadim")

	return data



def printa(data):

	for i in data:

		if len(i) <1:

			continue

		else:

			for j in i:

				print(j)


data = init(data,10)
data = hasing(data,"dsadsa")
data = hasing(data,"veri")
data = hasing(data,"asd")
data = hasing(data,"fdsghfdgds")
data = hasing(data,"fdsghfeyrew")
data = hasing(data,"dsadsadsaaadsa")

data = delete(data,"dsadsadsaaadsa")


ara(data, "fdsghfdgds")

printa(data)