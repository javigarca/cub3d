for archivo in *.png; do
    # Verificar si el archivo es un archivo PNG
    if [ -f "$archivo" ]; then
        # Obtener el nombre base del archivo (sin la extensión)
        nombre_base=$(basename "$archivo" .png)
        
        # Convertir el archivo PNG a XPM
        convert "$archivo" "$nombre_base.xpm"
        
        echo "Archivo $archivo convertido a $nombre_base.xpm"
    fi
done