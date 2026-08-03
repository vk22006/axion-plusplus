#pragma once

/**
 * @file version.hpp
 * @brief Compile-time version constants for the axion library.
 *
 * Provides individual numeric components as well as a single
 * human-readable version string that follows Semantic Versioning
 * (https://semver.org): MAJOR.MINOR.PATCH.
 *
 * Increment @c VERSION_MAJOR for breaking API changes,
 * @c VERSION_MINOR for backward-compatible new features, and
 * @c VERSION_PATCH for backward-compatible bug fixes.
 */

namespace axion {
    //! Major version number. Incremented on breaking API changes.
    constexpr int VERSION_MAJOR = 0;

    //! Minor version number. Incremented on backward-compatible new features.
    constexpr int VERSION_MINOR = 1;

    //! Patch version number. Incremented on backward-compatible bug fixes.
    constexpr int VERSION_PATCH = 0;

    //! Full version string in "MAJOR.MINOR.PATCH" format.
    constexpr const char* VERSION = "0.1.0";
}