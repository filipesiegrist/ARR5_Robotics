import tkinter as tk
from tkinter import font
import requests
from PIL import ImageTk, Image
from pyfirmata import Arduino, util
import time
import serial

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
#board = pyfirmata.Arduino('/folder')


HEIGHT = 700
WIDTH = 1000

x_atual = 0
y_atual = 0
z_atual = 0

x_fut = 0
y_fut = 0
z_fut = 0

cont = 0

def enviar_coordenadas(entry_x, entry_y, entry_z):

	#SerialWrite(entry_x, entry_y, entry_z)
	print("A coordenada eh: [%s, %s, %s]" % (entry_x, entry_y, entry_z))

def salvar_coordenadas():

	#SerialWrite(5)
	print("Coordenadas Salvas! [%i, %i, %i]" % (x_atual, y_atual, z_atual))

def receber_coordenadas():

	global x_atual
	global y_atual
	global z_atual

	ser.write(b'1 46')
	time.sleep(2)
	ser.write(b'66')
	line1 = ""
	line2 = ""
	line3 = ""

	while (len(line3) == 0):
		line = ser.readline()
		print(line)

	#x_atual = SerialRead()
	#y_atual = SerialRead()
	#z_atual = SerialRead()

	#print("Coordenadas Recebidas! [%i, %i, %i]" % (x_atual, y_atual, z_atual))
	#coord_upper.config(text='X = %i\n\nY = %i\n\nZ = %i\n\n' % (x_atual, y_atual, z_atual))

def funcao_global(x): 

	if (x == 5):
		salvar_coordenadas()

	time.sleep(1)




def inc_x():
	global x_fut
	x_fut += 1
	coord_lower.config(text='X = %i\n\nY = %i\n\nZ = %i\n\n' % (x_fut, y_fut, z_fut))

def inc_y():
	global y_fut
	y_fut += 1
	coord_lower.config(text='X = %i\n\nY = %i\n\nZ = %i\n\n' % (x_fut, y_fut, z_fut))

def inc_z():
	global z_fut
	z_fut += 1
	coord_lower.config(text='X = %i\n\nY = %i\n\nZ = %i\n\n' % (x_fut, y_fut, z_fut))

def dec_x():
	global x_fut
	x_fut -= 1
	coord_lower.config(text='X = %i\n\nY = %i\n\nZ = %i\n\n' % (x_fut, y_fut, z_fut))

def dec_y():
	global y_fut
	y_fut -= 1
	coord_lower.config(text='X = %i\n\nY = %i\n\nZ = %i\n\n' % (x_fut, y_fut, z_fut))

def dec_z():
	global z_fut
	z_fut -= 1
	coord_lower.config(text='X = %i\n\nY = %i\n\nZ = %i\n\n' % (x_fut, y_fut, z_fut))

root = tk.Tk()

canvas = tk.Canvas(root, height=HEIGHT, width=WIDTH, bg='#cccccc')
canvas.pack()

img_frame = tk.Frame(root, highlightthickness=3, bd=5, highlightbackground='black')
img_frame.place(relx=0.04, rely = 0.2, relwidth=0.4, relheight=0.7)

img = ImageTk.PhotoImage(Image.open("robo.jpg"))  
background_label = tk.Label(img_frame, image=img)
background_label.place(x=0, y=0, relwidth=1, relheight=1)

label_title = tk.Label(root, text='Interface do ARR5', font=('Tahoma', 32), anchor='n', bg='#cccccc')
label_title.place(relx=0.5, rely = 0.05, anchor='n')

upper_frame = tk.Frame(root, highlightthickness=3, bd=5, highlightbackground='black')
upper_frame.place(relx=0.7, rely = 0.25, relwidth=0.4, relheight=0.25, anchor='n')

lower_frame = tk.Frame(root, highlightthickness=3, bd=5, highlightbackground='black')
lower_frame.place(relx=0.7, rely = 0.60, relwidth=0.4, relheight=0.25, anchor='n')

label_upper = tk.Label(upper_frame, text='Coordenadas Atuais do ARR5', font=('Tahoma', 16), anchor='n')
label_upper.place(relwidth=1, relheight=0.3)

label_lower = tk.Label(lower_frame, text='Alterar as Coordenadas do ARR5', font=('Tahoma', 16), anchor='n')
label_lower.place(relwidth=1, relheight=0.3)

coord_upper = tk.Label(upper_frame, text='X = %i\n\nY = %i\n\nZ = %i\n\n' % (x_atual, y_atual, z_atual), font=('Tahoma', 16), anchor='w')
coord_upper.place(relwidth=0.5, relheight=0.8, relx=0.02, rely=0.23)

coord_lower = tk.Label(lower_frame, text='X = %i\n\nY = %i\n\nZ = %i\n\n' % (x_fut, y_fut, z_fut), font=('Tahoma', 16), anchor='w')
coord_lower.place(relwidth=0.5, relheight=0.8, relx=0.02, rely=0.23)

button_inc_x = tk.Button(lower_frame, text="+", font=40, command=inc_x)
button_inc_x.place(relx=0.6, rely=0.2, relwidth=0.15, relheight=0.15)

button_dec_x = tk.Button(lower_frame, text="-", font=40, command=dec_x)
button_dec_x.place(relx=0.45, rely=0.2, relwidth=0.15, relheight=0.15)

button_inc_y = tk.Button(lower_frame, text="+", font=40, command=inc_y)
button_inc_y.place(relx=0.6, rely=0.44, relwidth=0.15, relheight=0.15)

button_dec_y = tk.Button(lower_frame, text="-", font=40, command=dec_y)
button_dec_y.place(relx=0.45, rely=0.44, relwidth=0.15, relheight=0.15)

button_inc_z = tk.Button(lower_frame, text="+", font=40, command=inc_z)
button_inc_z.place(relx=0.6, rely=0.68, relwidth=0.15, relheight=0.15)

button_dec_z = tk.Button(lower_frame, text="-", font=40, command=dec_z)
button_dec_z.place(relx=0.45, rely=0.68, relwidth=0.15, relheight=0.15)

frame_xyz = tk.Frame(root, highlightthickness=3, bd=5, highlightbackground='black')
frame_xyz.place(relx=0.70, rely = 0.05, relwidth=0.25, relheight=0.15)

label_xyz = tk.Label(frame_xyz, text='X =\n\nY =\n\nZ =', font=('Tahoma', 16))
label_xyz.place(relwidth=0.2, relheight=1)

x_frame = tk.Frame(frame_xyz)
x_frame.place(relx=0.2, relwidth=0.45, relheight=0.3)

entry_x = tk.Entry(x_frame, font=40)
entry_x.place(relwidth=1, relheight=1)

y_frame = tk.Frame(frame_xyz)
y_frame.place(relx=0.2, rely = 0.3, relwidth=0.45, relheight=0.3)

entry_y = tk.Entry(y_frame, font=40)
entry_y.place(relwidth=1, relheight=1)

z_frame = tk.Frame(frame_xyz)
z_frame.place(relx=0.2, rely = 0.6, relwidth=0.45, relheight=0.3)

entry_z = tk.Entry(z_frame, font=40)
entry_z.place(relwidth=1, relheight=1)

button_send = tk.Button(frame_xyz, text="Enviar\n\nCoord", font=40, command=lambda: enviar_coordenadas(entry_x.get(), entry_y.get(), entry_z.get()))
button_send.place(relwidth=0.3, relheight=0.9, relx=0.7)

button_save = tk.Button(upper_frame, text="Salvar\n\nCoordenadas", font=40, command=salvar_coordenadas)
button_save.place(relwidth=0.3, relheight=0.5, relx=0.3, rely=0.25)

button_receive = tk.Button(upper_frame, text="Receber\n\nCoordenadas", font=40, command=receber_coordenadas)
button_receive.place(relwidth=0.3, relheight=0.5, relx=0.6, rely=0.25)

def rec():
    #SerialRead(numero)
	#funcao_global(numero)
	receber_coordenadas()
	print("loop")
	root.after(1000, rec)

root.after(1000, rec)
root.mainloop()