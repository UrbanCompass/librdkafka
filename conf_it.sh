STATIC_LIB_libzstd=/opt/homebrew/Cellar/zstd/1.5.6/lib/libzstd.a \
    STATIC_LIB_libcrypto=/opt/homebrew/Cellar/openssl@3/3.3.1/lib/libcrypto.a \
    STATIC_LIB_libcurl=/opt/homebrew/Cellar/curl/8.8.0/lib/libcurl.a \
    STATIC_LIB_libopenssl=/opt/homebrew/Cellar/openssl@3/3.3.1/lib/libssl.a \
    #LIBS=/opt/homebrew/Cellar \
    LDFLAGS=-l/opt/homebrew/Cellar/openssl@3/3.3.1/lib/libssl.a,-l/opt/homebrew/Cellar/curl/8.8.0/lib/libcurl.a,-l/opt/homebrew/Cellar/openssl@3/3.3.1/lib/libcrypto.a \
    #LDFLAGS=-L/opt/homebrew/Cellar/openssl@3/3.3.1/lib,-L/opt/homebrew/Cellar/curl/8.8.0/lib,-L/opt/homebrew/Cellar/openssl@3/3.3.1/lib \
    PKG_CONFIG_PATH="/opt/homebrew/Cellar/openssl@3 /opt/homebrew/Cellar/curl /opt/homebrew/Cellar/cyrus-sasl /opt/homebrew/opt/cyrus-sasl/2.1.28_2/lib/pkgconfig" \
    CFLAGS="-I/opt/homebrew/Cellar/openssl@3/3.3.1/include -I/opt/homebrew/Cellar/openssl@3/3.3.1/include -I/opt/homebrew/Cellar/cyrus-sasl/2.1.28_2/include -L/opt/homebrew/Cellar/cyrus-sasl/2.1.28_2/lib" \
    ./configure \
    --prefix=/opt/homebrew \
    --libdir=/opt/homebrew/Cellar \
    --enable-static \
    --enable-sasl \
    --enable-curl \
    --arch=arm64

