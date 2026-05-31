# RAFALR-METIN-GM-AFFECTS-SYSTEM

Distinct GM affects and visible staff prefixes for Martysama serverfiles.

[English](#english) | [Polski](#polski)

![Example](Example.jpg)

External example: https://metin2.download/picture/YJeeJ4r2rXR337Pn6a76D2cyj7c1bP29/.jpg

## Polski

### Opis

System dodaje osobne efekty GM dla wybranych rang administracji oraz pokazuje nad postacią gracza prefiks, np. `[HA]`, `[TECH]`, `[GA]`, `[GM]`, `[TGM]`, `[TUT]`, zamiast standardowego poziomu postaci.

Rozwiązanie zostało przygotowane z pomocą sztucznej inteligencji na podstawie publicznego tematu społeczności. Patch jest przygotowany pod Martysama serverfiles.

Najważniejsza zmiana polega na oddzieleniu wyglądu GM od poziomu uprawnień administratora. Poziom uprawnień dalej pozostaje w kolumnie `mAuthority`, a za sam prefiks oraz efekt odpowiada nowa kolumna `prefix` w tabeli `gmlist`.

### Funkcje

- osobny efekt wizualny dla prefiksów `HA`, `TECH`, `GA`, `GM`, `TGM`, `TUT`
- prefiks nad postacią GM zamiast poziomu postaci
- niezależny prefiks wizualny bez zmiany realnych uprawnień GM
- domyślny prefiks `GM`
- odświeżanie efektu po zmianie listy GM
- gotowe fragmenty kodu dla serwera, binarki klienta, roota i locale

### Struktura paczki

- `server/gmlist.sql` - zapytanie SQL dodające kolumnę `prefix`
- `svn/server/common` - zmiany dla `CommonDefines.h` i `tables.h`
- `svn/server/db` - zmiany dla pobierania listy GM z bazy
- `svn/server/game` - affecty, prefiks GM, odświeżanie efektu i obsługa postaci
- `svn/client/UserInterface` - define, ID affectów, eksport do Pythona i wyświetlanie prefiksu
- `client/root` - rejestracja efektów i ścieżki locale
- `client/locale/xx/effect` - miejsce na pliki `.mse` i `.tga` efektów

### Instalacja

1. Zrób kopię zapasową źródeł serwera, źródeł klienta, plików root/locale oraz bazy danych.

2. Wykonaj SQL z pliku `server/gmlist.sql` w bazie, w której znajduje się tabela `gmlist`:

```sql
ALTER TABLE gmlist
ADD COLUMN prefix ENUM('HA','TECH','GA','GM','TGM','TUT') NOT NULL DEFAULT 'GM' AFTER mAuthority;
```

3. W źródłach serwera dodaj fragmenty z katalogu `svn/server` do odpowiednich plików:

- `common/CommonDefines.h`
- `common/tables.h`
- `db/ClientManager.cpp`
- `game/src/affect.h`
- `game/src/char.cpp`
- `game/src/char.h`
- `game/src/gm.cpp`
- `game/src/gm.h`
- `game/src/input_db.cpp`

4. W źródłach klienta dodaj fragmenty z katalogu `svn/client/UserInterface` do odpowiednich plików:

- `Locale_inc.h`
- `InstanceBase.h`
- `InstanceBase.cpp`
- `InstanceBaseEffect.cpp`
- `PythonApplicationModule.cpp`
- `PythonCharacterModule.cpp`

5. W plikach root klienta dodaj fragmenty z katalogu `client/root`:

- `localeinfo.py`
- `playersettingmodule.py`

6. Dodaj pliki efektów do locale klienta:

```text
locale/<twój_locale>/effect/ha.mse
locale/<twój_locale>/effect/ha.tga
locale/<twój_locale>/effect/tech.mse
locale/<twój_locale>/effect/tech.tga
locale/<twój_locale>/effect/ga.mse
locale/<twój_locale>/effect/ga.tga
locale/<twój_locale>/effect/gm.mse
locale/<twój_locale>/effect/tgm.mse
locale/<twój_locale>/effect/tgm.tga
locale/<twój_locale>/effect/tut.mse
locale/<twój_locale>/effect/tut.tga
```

7. Przebuduj `game`, `db` oraz binarkę klienta, a następnie spakuj ponownie `root` i `locale`.

8. Zrestartuj serwer albo przeładuj listę GM, jeżeli Twoje pliki obsługują reload administracji.

### Użycie

Prefiks ustawiasz w tabeli `gmlist`, niezależnie od `mAuthority`.

Przykład:

```sql
UPDATE gmlist
SET prefix = 'HA'
WHERE mName = 'NickGM';
```

Dostępne wartości:

```text
HA, TECH, GA, GM, TGM, TUT
```

Jeżeli kolumna `prefix` jest pusta lub nie zostanie ustawiona, system użyje domyślnego prefiksu `GM`.

### Ważne uwagi

- `mAuthority` dalej odpowiada za realne uprawnienia administratora.
- `prefix` odpowiada tylko za wyświetlany tag oraz efekt wizualny.
- ID affectów po stronie klienta są celowo przesunięte o `-1` względem serwera. Nie zmieniaj ich bez sprawdzenia mapowania flag affectów.
- Jeżeli zmieniasz nazwy prefiksów, zaktualizuj równocześnie SQL, `RefreshGMAffect`, pliki root i rejestrację efektów.
- Pliki `.mse` mogą wymagać dodatkowych tekstur. Upewnij się, że wszystkie zasoby wskazane w `.mse` znajdują się w kliencie.

### Autor

Patch przygotowany przez RAFALR z wykorzystaniem wsparcia sztucznej inteligencji.

## English

### Description

This system adds distinct GM visual effects for selected staff prefixes and displays a staff prefix above the character, for example `[HA]`, `[TECH]`, `[GA]`, `[GM]`, `[TGM]`, `[TUT]`, instead of the normal character level.

The solution was developed with the help of artificial intelligence and based on a public community topic. This patch was created for Martysama serverfiles.

The main idea is to separate the visual GM affect from the administrator permission level. The real permission level still stays in the `mAuthority` column, while the displayed prefix and visual effect are controlled by the new `prefix` column in the `gmlist` table.

### Features

- separate visual affect for `HA`, `TECH`, `GA`, `GM`, `TGM`, `TUT`
- staff prefix above the GM character instead of the character level
- visual prefix separated from real GM permissions
- default `GM` prefix
- affect refresh after GM list reload
- ready snippets for server source, client source, root and locale

### Package Structure

- `server/gmlist.sql` - SQL query adding the `prefix` column
- `svn/server/common` - changes for `CommonDefines.h` and `tables.h`
- `svn/server/db` - changes for loading the GM list from the database
- `svn/server/game` - affects, GM prefix, affect refresh and character handling
- `svn/client/UserInterface` - define, affect IDs, Python exports and prefix display
- `client/root` - effect registration and locale paths
- `client/locale/xx/effect` - place for `.mse` and `.tga` effect files

### Installation

1. Make a backup of your server source, client source, root/locale files and database.

2. Execute the SQL from `server/gmlist.sql` in the database where your `gmlist` table exists:

```sql
ALTER TABLE gmlist
ADD COLUMN prefix ENUM('HA','TECH','GA','GM','TGM','TUT') NOT NULL DEFAULT 'GM' AFTER mAuthority;
```

3. Add the snippets from `svn/server` to the matching server source files:

- `common/CommonDefines.h`
- `common/tables.h`
- `db/ClientManager.cpp`
- `game/src/affect.h`
- `game/src/char.cpp`
- `game/src/char.h`
- `game/src/gm.cpp`
- `game/src/gm.h`
- `game/src/input_db.cpp`

4. Add the snippets from `svn/client/UserInterface` to the matching client source files:

- `Locale_inc.h`
- `InstanceBase.h`
- `InstanceBase.cpp`
- `InstanceBaseEffect.cpp`
- `PythonApplicationModule.cpp`
- `PythonCharacterModule.cpp`

5. Add the snippets from `client/root` to the client root files:

- `localeinfo.py`
- `playersettingmodule.py`

6. Add the effect files to your client locale:

```text
locale/<your_locale>/effect/ha.mse
locale/<your_locale>/effect/ha.tga
locale/<your_locale>/effect/tech.mse
locale/<your_locale>/effect/tech.tga
locale/<your_locale>/effect/ga.mse
locale/<your_locale>/effect/ga.tga
locale/<your_locale>/effect/gm.mse
locale/<your_locale>/effect/tgm.mse
locale/<your_locale>/effect/tgm.tga
locale/<your_locale>/effect/tut.mse
locale/<your_locale>/effect/tut.tga
```

7. Rebuild `game`, `db` and the client binary, then repack `root` and `locale`.

8. Restart the server or reload the GM list if your files support admin reload.

### Usage

Set the prefix in the `gmlist` table independently from `mAuthority`.

Example:

```sql
UPDATE gmlist
SET prefix = 'HA'
WHERE mName = 'GMName';
```

Available values:

```text
HA, TECH, GA, GM, TGM, TUT
```

If the `prefix` column is empty or not configured, the system falls back to the default `GM` prefix.

### Important Notes

- `mAuthority` still controls the real administrator permission level.
- `prefix` controls only the displayed tag and the visual affect.
- Client-side affect IDs are intentionally shifted by `-1` compared to the server-side IDs. Do not change them without checking the affect flag mapping.
- If you change prefix names, update the SQL, `RefreshGMAffect`, root files and effect registration at the same time.
- `.mse` files may require additional textures. Make sure every asset referenced by the `.mse` files exists in the client.

### Credits

Patch prepared by RAFALR with the support of artificial intelligence.
