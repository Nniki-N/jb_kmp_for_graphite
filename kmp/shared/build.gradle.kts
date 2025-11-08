plugins {
    alias(libs.plugins.kotlinMultiplatform)
    application
}

kotlin {
    jvm()

    macosArm64("native") {
        binaries {
            sharedLib {
                baseName = "matrix"
            }
            executable {
                entryPoint = "main"
                linkerOpts("-L${projectDir.resolve("../../cpp").absoluteFile.canonicalPath}")
                linkerOpts("-lmatrix")
                linkerOpts("-rpath", projectDir.resolve("../../cpp").absoluteFile.canonicalPath)

                runTask?.environment(
                    "DYLD_LIBRARY_PATH",
                    projectDir.resolve("../../cpp").absoluteFile.canonicalPath
                )

            }

        }

        compilations.getByName("main") {
            cinterops {
                val matrix by creating {
                    definitionFile = file("src/nativeInterop/cinterop/matrix.def")
                    packageName = "matrix"
                    includeDirs.allHeaders(projectDir.resolve("../../cpp").absoluteFile.canonicalPath)
                }
            }
        }
    }

    sourceSets {
        val commonMain by getting
        val commonTest by getting {
            dependencies {
                implementation(kotlin("test"))
            }
        }

        val jvmMain by getting
        val jvmTest by getting {
            dependsOn(commonTest)
            kotlin.srcDir("src/jvmTest/kotlin")
            dependencies {
                implementation(kotlin("test-junit"))
            }
        }

        val nativeMain by getting
        val nativeTest by getting {
            dependsOn(commonTest)
            kotlin.srcDir("src/nativeTest/kotlin")
            dependencies {
                implementation(kotlin("test"))
            }
        }

    }
}

tasks.register<JavaExec>("runJvm") {
    group = "application"
    description = "Run JVM main with JNI"

    mainClass.set("MainKt")

    val jvmCompilation = kotlin.targets.getByName("jvm").compilations.getByName("main")
    classpath = files(jvmCompilation.output.allOutputs, jvmCompilation.runtimeDependencyFiles)

    systemProperty("java.library.path", projectDir.resolve("../../cpp").absoluteFile.canonicalPath)
}

val matrixLibName: String = when {
    org.gradle.internal.os.OperatingSystem.current().isMacOsX -> "libmatrix.dylib"
    org.gradle.internal.os.OperatingSystem.current().isLinux -> "libmatrix.so"
    org.gradle.internal.os.OperatingSystem.current().isWindows -> "matrix.dll"
    else -> error("Unsupported operating system")
}

val copyMatrixLib by tasks.registering(Copy::class) {
    description = "Copy libmatrix to build directory before running native tests"

    from(projectDir.resolve("../../cpp/$matrixLibName").absoluteFile.canonicalPath)
    into("${buildDir.parentFile}")
}

val copyMatrixLibSecond by tasks.registering(Copy::class) {
    description = "Copy libmatrix to build directory before running native tests"

    from(projectDir.resolve("../../cpp/$matrixLibName").absoluteFile.canonicalPath)
    into("${buildDir.parentFile.parentFile}")
}

tasks.named("cinteropMatrixNative") {
    dependsOn(copyMatrixLib)
    dependsOn(copyMatrixLibSecond)
}
