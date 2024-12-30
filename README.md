# Projecte INEP

## Resum
Aquest projecte implementa un sistema integral per a la gestió de sessions d'usuari, visualització de continguts i diverses consultes en una plataforma audiovisual. Inclou funcionalitats com registrar usuaris, iniciar sessió, visualitzar pel·lícules i capítols, i fer consultes específiques a la base de dades.

## Instruccions de Configuració

### Prerequisits
- **Connector MySQL C++**:
  Instal·leu la biblioteca requerida amb la següent comanda:
  ```bash
  apt-get install libmysqlcppconn-dev
  ```

### Passos per Configurar i Executar
1. Cloneu el repositori:
   ```bash
   git clone https://github.com/Cesconcins/INEP.git
   ```
2. Aneu al directori del projecte:
   ```bash
   cd INEP
   ```
3. Compileu el projecte utilitzant el `Makefile` proporcionat:
   ```bash
   make
   ```
4. Executeu l'aplicació:
   ```bash
   ./inep
   ```

### Configuració de la Base de Dades
La connexió amb la base de dades MySQL es gestiona mitjançant els fitxers de configuració ubicats a la carpeta `sistema`. Aquests fitxers garanteixen una integració sense problemes i no requereixen ajustaments manuals tret que canviïn les credencials de la base de dades.

Si es necessita una configuració manual, editeu els paràmetres de connexió al fitxer de configuració corresponent o proporcioneu els detalls quan l'aplicació ho sol·liciti.

## Estructura del Projecte

- **`sistema/`**: Conté els fitxers del sistema responsables de la connectivitat amb la base de dades i altres operacions fonamentals.
- **`controladors/`**: Inclou els controladors que implementen la lògica de negoci per als diversos casos d'ús.
- **`passareles/`**: Gestiona la interacció entre l'aplicació i la base de dades.
- **`presentacio/`**: Gestiona la interfície d'usuari i mostra la informació a l'usuari.

## Funcionalitats

1. **Gestió d'Usuaris**:
   - Registrar, modificar i esborrar usuaris.
   - Iniciar i tancar sessió.

2. **Visualització de Continguts**:
   - Visualitzar pel·lícules i capítols.

3. **Consultes**:
   - Consultar visualitzacions.
   - Consultar properes estrenes.
   - Consultar últimes novetats.
   - Consultar les pel·lícules més vistes.

## Proves i Depuració
L'aplicació ha estat provada amb proves unitàries, proves d'integració i simulacions d'interacció d'usuari. Totes les funcionalitats s'han validat en escenaris realistes per garantir la seva robustesa.

## Autors

- **Eduard Cole**: Gestió d'usuaris i configuració de la base de dades.
- **Pau Alcazar**: Funcionalitats de visualització.
- **Francesco Oncins**: Funcionalitats de consultes.

## Repositori
Trobareu la implementació completa al GitHub:
[Repositori GitHub del Projecte INEP](https://github.com/Cesconcins/INEP.git)
