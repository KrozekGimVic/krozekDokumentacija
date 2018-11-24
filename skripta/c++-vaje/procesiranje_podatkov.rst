.. |nbsp| unicode:: 0xA0
   :trim:

Procesiranje podatkov
=====================

Dano imaš datoteko :download:`tunel.zip<datoteke/tunel.tar.bz2>`, ki vsebuje (izmišljene) podatke iz kamer (velik in
majhen primer),
ki snemajo promet na obeh koncih tunela.
Za vsak avto, ki gre v tunel ali iz tunela, se zabeleži
njegova registrska tablica, tip avtomobila, časovna značka (milisekunde od 1. 1.
1970) in ID kamere ki je naredila vnos.

Tunel je dolg 3.2 kilometra, omejitev pa je 100 km/h za osebna vozila in motorje
ter 80 km/h za tovornjake in avtobuse. Drugih tipov vozil ne podpiramo.  Kamere
z ID ``CAM001``, ``CAM002``, ``CAM003`` in ``CAM007`` so na eni strani tunela, kamere z ID
``CAM043``, ``CAM052``, ``CAM016``, ``CAM008``, ``CAM010`` pa na drugi.

Vsako vozilo je pravilnoma zabeleženo sodo mnogokrat, tako da lahko izračunamo,
ali je prekoračilo hitrost. Izpiši tablice vseh vozila, ki so vozila vsaj 5% čez
omejitev!

Bonus naloga (za čast in slavo): pomisli na vse možne slabe podatke in
poskrbi, da se tvoj program ne sesuje še pri tako grdi vhodni datoteki.

Pomoč
-----

V pomoč vam je lahko splodnja funkcija ``split``:

.. code-block:: cpp

  std::vector<std::string> split(const std::string& str, const std::string& delim) {
      assert(!delim.empty() && "Delimiter must not be empty.");
      std::vector<std::string> tokens;
      size_t prev = 0, pos = 0;
      do {
          pos = str.find(delim, prev);
          if (pos == std::string::npos) pos = str.length();
          tokens.emplace_back(str.substr(prev, pos-prev));
          prev = pos + delim.length();
      } while (pos < str.length() && prev < str.length());
      if (prev == str.length()) tokens.emplace_back("");
      return tokens;
  }

Za tip vozila uporabite primeren ``enum``. Več o tem si lahko preberete v poglavju :ref:`enumcpp`.

Za pomoč je na voljo tudi primer podobne naloge: glej datoteko :download:`ocene.cpp<datoteke/ocene.cpp>` in podatke :download:`ocene.txt<datoteke/ocene.txt>`
