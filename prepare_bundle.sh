#!/usr/bin/env sh
# This script install all the assets into the generated bundle

BUNDLE_NAME="ultrapong"
BUNDLE_DIR="bin"
BUNDLE_PATH="$BUNDLE_DIR/$BUNDLE_NAME.app"
BUNDLE_RESOURCES_DIR="$BUNDLE_PATH/Contents/Resources"

ASSETS_DIR="asset"
ASSETS=$ASSETS_DIR/*

# Verify if the bundle has been generated
if [ -d "$BUNDLE_PATH" ]; then

    # Verify if there assets are already inside the bundle
    if [ -d "$BUNDLE_RESOURCES_DIR" ]; then
        rm -r "$BUNDLE_RESOURCES_DIR"
    fi

    # Create the resources directory
    mkdir "$BUNDLE_RESOURCES_DIR"
    
    # Copying all assets into the resources folder
    for asset in $ASSETS 
    do
        cp "$asset" "$BUNDLE_RESOURCES_DIR/$(basename $asset)"
    done
else
    # Must build the project before
    echo "Please build the game using CMake before running this script."
fi
