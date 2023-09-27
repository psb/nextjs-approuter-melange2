/** @type {import('next').NextConfig} */
const nextConfig = {
  webpack: function (config, context) {
    config.watchOptions = {
      poll: 1000,
      aggregateTimeout: 300,
    };
    return config;
  },
};

module.exports = nextConfig;
