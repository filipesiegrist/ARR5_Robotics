import tkinter as tk
from tkinter import font
import requests
from PIL import ImageTk, Image
from pyfirmata import Arduino, util
import time
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

HEIGHT = 700
WIDTH = 1000

x_atual = 0
y_atual = 0
z_atual = 0

x_fut = 0
y_fut = 0
z_fut = 0

cont = 0

def enviar_coordenadas(entry_j1, entry_j2, entry_j3, entry_g):

	ser.reset_input_buffer()
	ser.write(b'1 ')
	ser.write(str(entry_j1).encode('ascii'))
	time.sleep(2)

	ser.write(b'2 ')
	ser.write(str(entry_j2).encode('ascii'))
	time.sleep(2)

	ser.write(b'3 ')
	ser.write(str(entry_j3).encode('ascii'))
	time.sleep(2)

	ser.write(b'4 ')
	ser.write(str(entry_g).encode('ascii'))
	time.sleep(2)

	line1 = ""
	line2 = ""
	line3 = ""
	line4 = ""
	while (len(line4) == 0):
		line1 = ser.readline().decode().strip('\r\n')
		line2 = ser.readline().decode().strip('\r\n')
		line3 = ser.readline().decode().strip('\r\n')
		line4 = ser.readline().decode().strip('\r\n')
	
	print(line1)
	print(line2)
	print(line3)
	print(line4)

	label_res.config(text='%s' % (line1), font=10, anchor='w', justify='left')



def salvar_coordenadas():
	ser.reset_input_buffer()

	ser.write(b'5')
	time.sleep(1)

	line1 = ser.readline().decode().strip('\r\n')
	label_res.config(text='%s' % (line1), font=10, anchor='w', justify='left')

def receber_coordenadas():
	ser.reset_input_buffer()

	ser.write(b'66')
	line1 = ""
	line2 = ""
	line3 = ""

	while (len(line3) == 0):
		resposta = ser.readline().decode().strip('\r\n')
		line1 = ser.readline().decode().strip('\r\n')
		line2 = ser.readline().decode().strip('\r\n')
		line3 = ser.readline().decode().strip('\r\n')
	
	print(resposta)
	print(line1)
	print(line2)
	print(line3)
	
	coord_upper.config(text='%s\n%s\n%s\n%s' % (resposta, line1, line2, line3), font=10, anchor='w', justify='left')
	label_res.config(text='%s' % (resposta), font=10, anchor='w', justify='left')

	ser.write(b'55')
	line4 = ""
	line5 = ""
	line6 = ""
	
	while (len(line6) == 0):
		line4 = ser.readline().decode().strip('\r\n')
		line5 = ser.readline().decode().strip('\r\n')
		line6 = ser.readline().decode().strip('\r\n')
	
	print(line4)
	print(line5)
	print(line6)

	label_res.config(text='%s' % (line4), font=10, anchor='w', justify='left')
	coord_lower.config(text='%s\n%s\n%s' % (line4, line5, line6), font=10, anchor='w', justify='left')

def start():
	ser.reset_input_buffer()
	ser.write(b'6')
	time.sleep(1)

	msg = ser.readline().decode().strip('\r\n')
	print(msg)
	label_res.config(text='%s' % (msg), font=10, anchor='w', justify='left')

def reset():
	ser.reset_input_buffer()
	ser.write(b'7')
	time.sleep(1)

	msg = ser.readline().decode().strip('\r\n')
	label_res.config(text='%s' % (msg), font=10, anchor='w', justify='left')
	print(msg)

def stop():
	ser.reset_input_buffer()
	ser.write(b'404')
	time.sleep(1)

	msg = ser.readline().decode().strip('\r\n')
	label_res.config(text='%s' % (msg), font=10, anchor='w', justify='left')
	print(msg)

def inc_x():
	ser.reset_input_buffer()
	ser.write(b'8')
	time.sleep(1)

	msg = ser.readline().decode().strip('\r\n')
	label_res.config(text='%s' % (msg), font=10, anchor='w', justify='left')
	print(msg)

def inc_y():
	ser.reset_input_buffer()
	ser.write(b'10')
	time.sleep(1)

	msg = ser.readline().decode().strip('\r\n')
	label_res.config(text='%s' % (msg), font=10, anchor='w', justify='left')
	print(msg)

def inc_z():
	ser.reset_input_buffer()
	ser.write(b'12')
	time.sleep(1)

	msg = ser.readline().decode().strip('\r\n')
	label_res.config(text='%s' % (msg), font=10, anchor='w', justify='left')
	print(msg)

def dec_x():
	ser.reset_input_buffer()
	ser.write(b'9')
	time.sleep(1)

	msg = ser.readline().decode().strip('\r\n')
	label_res.config(text='%s' % (msg), font=10, anchor='w', justify='left')
	print(msg)

def dec_y():
	ser.reset_input_buffer()
	ser.write(b'11')
	time.sleep(1)

	msg = ser.readline().decode().strip('\r\n')
	label_res.config(text='%s' % (msg), font=10, anchor='w', justify='left')
	print(msg)

def dec_z():
	ser.reset_input_buffer()
	ser.write(b'13')
	time.sleep(1)

	msg = ser.readline().decode().strip('\r\n')
	label_res.config(text='%s' % (msg), font=10, anchor='w', justify='left')
	print(msg)

root = tk.Tk()

canvas = tk.Canvas(root, height=HEIGHT, width=WIDTH, bg='#cccccc')
canvas.pack()

img_frame = tk.Frame(root, highlightthickness=3, bd=5, highlightbackground='black')
img_frame.place(relx=0.04, rely = 0.2, relwidth=0.4, relheight=0.7)

img = ImageTk.PhotoImage(Image.open("robo.jpg"))  
background_label = tk.Label(img_frame, image=img)
background_label.place(x=0, y=0, relwidth=1, relheight=1)

label_title = tk.Label(root, text='Interface do ARR5', font=('Tahoma', 32), anchor='n', bg='#cccccc')
label_title.place(relx=0.25, rely = 0.05, anchor='n')

upper_frame = tk.Frame(root, highlightthickness=3, bd=5, highlightbackground='black')
upper_frame.place(relx=0.7, rely = 0.25, relwidth=0.4, relheight=0.25, anchor='n')

lower_frame = tk.Frame(root, highlightthickness=3, bd=5, highlightbackground='black')
lower_frame.place(relx=0.7, rely = 0.60, relwidth=0.4, relheight=0.25, anchor='n')

label_upper = tk.Label(upper_frame, text='Angulos Atuais do ARR5', font=('Tahoma', 16), anchor='n')
label_upper.place(relwidth=1, relheight=0.3)

label_lower = tk.Label(lower_frame, text='Coordenadas Atuais do ARR5', font=('Tahoma', 16), anchor='n')
label_lower.place(relwidth=1, relheight=0.3)

coord_upper = tk.Label(upper_frame, text='Theta1 = %i\nTheta2 = %i\nTheta3 = %i\n' % (x_atual, y_atual, z_atual), font=('Tahoma', 12), anchor='w')
coord_upper.place(relwidth=1, relheight=0.8, relx=0.02, rely=0.23)

coord_lower = tk.Label(lower_frame, text='X = %i\nY = %i\nZ = %i\n' % (x_fut, y_fut, z_fut), font=('Tahoma', 12), anchor='w')
coord_lower.place(relwidth=0.5, relheight=0.8, relx=0.02, rely=0.23)

button_inc_x = tk.Button(lower_frame, text="+", font=40, command=inc_x)
button_inc_x.place(relx=0.6, rely=0.4, relwidth=0.15, relheight=0.15)

button_dec_x = tk.Button(lower_frame, text="-", font=40, command=dec_x)
button_dec_x.place(relx=0.45, rely=0.4, relwidth=0.15, relheight=0.15)

button_inc_y = tk.Button(lower_frame, text="+", font=40, command=inc_y)
button_inc_y.place(relx=0.6, rely=0.55, relwidth=0.15, relheight=0.15)

button_dec_y = tk.Button(lower_frame, text="-", font=40, command=dec_y)
button_dec_y.place(relx=0.45, rely=0.55, relwidth=0.15, relheight=0.15)

button_inc_z = tk.Button(lower_frame, text="+", font=40, command=inc_z)
button_inc_z.place(relx=0.6, rely=0.7, relwidth=0.15, relheight=0.15)

button_dec_z = tk.Button(lower_frame, text="-", font=40, command=dec_z)
button_dec_z.place(relx=0.45, rely=0.7, relwidth=0.15, relheight=0.15)

frame_xyz = tk.Frame(root, highlightthickness=3, bd=5, highlightbackground='black')
frame_xyz.place(relx=0.5, rely = 0.05, relwidth=0.4, relheight=0.15)

label_xyz = tk.Label(frame_xyz, text='Theta1 =\nTheta2 =\nTheta3 =\nGarra   =', font=('Tahoma', 11), justify='left')
label_xyz.place(relwidth=0.2, relheight=1)

x_frame = tk.Frame(frame_xyz)
x_frame.place(relx=0.2, relwidth=0.45, relheight=0.2, rely=0.1)

entry_j1 = tk.Entry(x_frame, font=40)
entry_j1.place(relwidth=1, relheight=1)

y_frame = tk.Frame(frame_xyz)
y_frame.place(relx=0.2, rely = 0.3, relwidth=0.45, relheight=0.2)

entry_j2 = tk.Entry(y_frame, font=40)
entry_j2.place(relwidth=1, relheight=1)

z_frame = tk.Frame(frame_xyz)
z_frame.place(relx=0.2, rely = 0.5, relwidth=0.45, relheight=0.2)

entry_j3 = tk.Entry(z_frame, font=40)
entry_j3.place(relwidth=1, relheight=1)

w_frame = tk.Frame(frame_xyz)
w_frame.place(relx=0.2, rely = 0.7, relwidth=0.45, relheight=0.2)

entry_g = tk.Entry(w_frame, font=40)
entry_g.place(relwidth=1, relheight=1)

button_send = tk.Button(frame_xyz, text="Enviar\n\nAng", font=40, command=lambda: enviar_coordenadas(entry_j1.get(), entry_j2.get(), entry_j3.get(), entry_g.get()))
button_send.place(relwidth=0.3, relheight=0.8, relx=0.67, rely=0.1)

button_save = tk.Button(upper_frame, text="Salvar", font=40, command=salvar_coordenadas)
button_save.place(relwidth=0.5, relheight=0.18, relx=0.4, rely=0.42)

button_receive = tk.Button(upper_frame, text="Receber", font=40, command=receber_coordenadas)
button_receive.place(relwidth=0.5, relheight=0.18, relx=0.4, rely=0.22)

button_start = tk.Button(upper_frame, text="Iniciar", font=40, command=start)
button_start.place(relwidth=0.25, relheight=0.18, relx=0.4, rely=0.62)

button_reset = tk.Button(upper_frame, text="Reset", font=40, command=reset)
button_reset.place(relwidth=0.5, relheight=0.18, relx=0.4, rely=0.82)

button_stop = tk.Button(upper_frame, text="Stop", font=40, command=stop)
button_stop.place(relwidth=0.25, relheight=0.18, relx=0.65, rely=0.62)

label_res = tk.Label(root, highlightthickness=3, bd=5, highlightbackground='black')
label_res.place(relx=0.5, rely=0.9, relwidth=0.4, relheight=0.05)

# while True:
# 	receber_coordenadas()
# 	sleep(1)

# def rec():
# 	receber_coordenadas()
# 	print("loop")
# 	root.after(1000, rec)

#root.after(1000, rec)
root.mainloop()