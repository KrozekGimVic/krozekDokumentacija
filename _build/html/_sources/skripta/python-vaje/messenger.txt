.. |nbsp| unicode:: 0xA0
   :trim:

Facebook messenger bot
======================

V tej vaji bomo naredili robota, ki zna brati svoja sporočila na Facebooku in
odgovarjati na njih s predpisanimi pravili.

Namestitev knjižnice
--------------------
Ker ne želimo začeti iz nič, bomo uporabili že narejeno knjižnico ``fbchat``.
Popravljena knjižnica, ki deluje dobro tudi s pythonom 3, je na voljo na
https://github.com/MKolman/fbchat.

Ustvarimo virtualno okolje in namestimo knjižnico.::

  virtualenv venv -p /bin/python3
  source venv/bin/activate
  pip install -e git+https://github.com/MKolman/fbchat.git#egg=fbchat


Enostaven primer kode, ki pošlje eno sporočilo:

.. code-block:: python

  from getpass import getpass
  import fbchat

  username = input("Username: ")
  password = getpass()
  client = fbchat.Client(username, password)

  friend = client.getUsers("Maks Kolman")[0]

  client.send(friend.uid, "Pozdravljen!")
