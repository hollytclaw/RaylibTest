const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{
        .default_target = .{
            .cpu_arch = .aarch64,
            .os_tag = .macos,
        },
    });
    const optimize = b.standardOptimizeOption(.{});

    const raylib_dep = b.dependency("raylib", .{
        .target = target,
        .optimize = optimize,
    });

    const exe = b.addExecutable(.{
        .name = "hello_raylib",
        .target = target,
        .optimize = optimize,
    });

    exe.addCSourceFile(.{
        .file = b.path("main.c"),
        .flags = &.{"-std=c99"},
    });

    exe.linkLibrary(raylib_dep.artifact("raylib"));
    exe.linkLibC();

    b.installArtifact(exe);
}
