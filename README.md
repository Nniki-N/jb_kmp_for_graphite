# jb_kmp_for_graphite

# Kotlin Multiplatform Dense Matrix Library

A small, self-contained dense matrix multiplication library implemented in C++, with a Kotlin Multiplatform interface.
It supports both JVM (via JNI) and Kotlin/Native (macOS/Linux/Windows).

## Build Instructions (tested only on macOS ARM64)

### 1. Build the Native Library (libmatrix)

Move to the cpp/ directory and compile the shared library for your platform:

### macOS (.dylib)
```bash
g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin" -fPIC -shared -o libmatrix.dylib matrix.cpp matrix_c.cpp matrix_jni.cpp
```


### Linux (.so)
```bash
g++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -fPIC -shared -o libmatrix.so matrix.cpp matrix_c.cpp matrix_jni.cpp
```

### Windows (.dll)
```bash
g++ -I"%JAVA_HOME%/include" -I"%JAVA_HOME%/include/win32" -shared -o matrix.dll matrix.cpp matrix_c.cpp matrix_jni.cpp -Wl,--out-implib,libmatrix.a
```

### 2. Clean the Kotlin Build

From the kmp/ directory, clean old Gradle outputs:
```bash
./gradlew clean
```

### 3. (Optional) Refresh Dependencies
```bash
./gradlew --refresh-dependencies
```

Needed if you’ve updated library versions or Gradle configuration.

### 4. Build the Kotlin/Native Executable
```bash
./gradlew :shared:compileKotlinNative
./gradlew :shared:linkDebugExecutableNative
```

### 5. Run the Native Demo
```bash
./gradlew :shared:runDebugExecutableNative
```

This executes nativeMain/kotlin/Main.kt, which performs a sample matrix multiplication and prints the result.

### 6. Run the JVM Demo
```bash
./gradlew :shared:runJvm
```

This runs jvmMain/kotlin/Main.kt.

### 7. Run Tests
```bash
./gradlew :shared:jvmTest
```

```bash
./gradlew :shared:nativeTest
```
